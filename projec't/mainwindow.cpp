#include "mainwindow.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QIntValidator>
#include <QLineEdit>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlField>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>
#include <QAbstractItemView>

// Заполните данными удалённой БД.
static const QString DB_HOST = QStringLiteral("your-host");
static const int DB_PORT = 5432;
static const QString DB_NAME = QStringLiteral("your-db");
static const QString DB_USER = QStringLiteral("your-user");
static const QString DB_PASS = QStringLiteral("your-password");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), model(new QSqlTableModel(this))
{
    ready = setupDb();
    setupUi();
    if (ready) {
        loadTables();
    }
}

bool MainWindow::setupDb()
{
    db = QSqlDatabase::addDatabase(QStringLiteral("QPSQL"));
    db.setHostName(DB_HOST);
    db.setPort(DB_PORT);
    db.setDatabaseName(DB_NAME);
    db.setUserName(DB_USER);
    db.setPassword(DB_PASS);

    if (!db.open()) {
        QMessageBox::critical(this, tr("Ошибка подключения"),
                              tr("Не удалось подключиться к БД:\n%1")
                                  .arg(db.lastError().text()));
        return false;
    }
    return true;
}

void MainWindow::setupUi()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);

    auto *top = new QHBoxLayout();
    tables = new QComboBox(central);
    tables->setPlaceholderText(tr("Таблица"));
    top->addWidget(tables, 1);

    refreshBtn = new QPushButton(tr("Обновить"), central);
    addBtn = new QPushButton(tr("Добавить"), central);
    editBtn = new QPushButton(tr("Изменить"), central);
    delBtn = new QPushButton(tr("Удалить"), central);
    for (auto *b : {refreshBtn, addBtn, editBtn, delBtn}) {
        top->addWidget(b);
    }
    layout->addLayout(top);

    view = new QTableView(central);
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->horizontalHeader()->setStretchLastSection(true);
    layout->addWidget(view, 1);

    status = new QLabel(tr("Готово"), central);
    layout->addWidget(status);

    setCentralWidget(central);
    resize(900, 600);

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    connect(tables, &QComboBox::currentTextChanged, this, &MainWindow::changeTable);
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(editBtn, &QPushButton::clicked, this, &MainWindow::editRow);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::deleteRow);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refresh);
}

void MainWindow::loadTables()
{
    tables->clear();
    QSqlQuery q(db);
    if (!q.exec(QStringLiteral("SELECT table_name FROM information_schema.tables "
                               "WHERE table_schema='public' ORDER BY table_name"))) {
        showError(q.lastError().text());
        return;
    }
    while (q.next()) {
        tables->addItem(q.value(0).toString());
    }
    if (tables->count()) {
        tables->setCurrentIndex(0);
    }
}

void MainWindow::changeTable(const QString &table)
{
    if (table.isEmpty())
        return;
    model->setTable(table);
    if (!model->select()) {
        showError(model->lastError().text());
        return;
    }
    view->resizeColumnsToContents();
    status->setText(tr("Таблица: %1").arg(table));
}

bool MainWindow::editRecord(QSqlRecord &rec, const QString &title)
{
    QDialog dlg(this);
    dlg.setWindowTitle(title);
    auto *layout = new QVBoxLayout(&dlg);
    auto *form = new QFormLayout();
    QVector<QLineEdit *> edits;
    edits.reserve(rec.count());

    for (int i = 0; i < rec.count(); ++i) {
        auto *edit = new QLineEdit(&dlg);
        edit->setText(rec.value(i).toString());
        const auto type = rec.field(i).type();
        if (type == QVariant::Int || type == QVariant::LongLong) {
            edit->setValidator(new QIntValidator(edit));
        } else if (type == QVariant::Double || type == QVariant::Float) {
            edit->setValidator(new QDoubleValidator(edit));
        }
        form->addRow(rec.fieldName(i) + ":", edit);
        edits << edit;
    }

    layout->addLayout(form);
    auto *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                         Qt::Horizontal, &dlg);
    layout->addWidget(buttons);
    connect(buttons, &QDialogButtonBox::accepted, &dlg, [&]() {
        for (int i = 0; i < rec.count(); ++i) {
            const QString v = edits[i]->text().trimmed();
            if (v.isEmpty()) {
                QMessageBox::warning(&dlg, tr("Проверка данных"),
                                     tr("Поле \"%1\" не может быть пустым.")
                                         .arg(rec.fieldName(i)));
                return;
            }
            rec.setValue(i, v);
        }
        dlg.accept();
    });
    connect(buttons, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    return dlg.exec() == QDialog::Accepted;
}

void MainWindow::addRow()
{
    if (!model->table().size())
        return;
    QSqlRecord rec = model->record();
    if (!editRecord(rec, tr("Добавить запись")))
        return;
    if (!model->insertRecord(-1, rec) || !model->submitAll()) {
        model->revertAll();
        showError(model->lastError().text());
    } else {
        status->setText(tr("Добавлено"));
    }
}

void MainWindow::editRow()
{
    const auto idx = view->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::information(this, tr("Редактирование"), tr("Выберите строку."));
        return;
    }
    QSqlRecord rec = model->record(idx.row());
    if (!editRecord(rec, tr("Изменить запись")))
        return;
    if (!model->setRecord(idx.row(), rec) || !model->submitAll()) {
        model->revertAll();
        showError(model->lastError().text());
    } else {
        status->setText(tr("Изменено"));
    }
}

void MainWindow::deleteRow()
{
    const auto idx = view->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::information(this, tr("Удаление"), tr("Выберите строку."));
        return;
    }
    if (QMessageBox::question(this, tr("Подтверждение"),
                              tr("Удалить выбранную запись?")) != QMessageBox::Yes)
        return;
    if (!model->removeRow(idx.row()) || !model->submitAll()) {
        model->revertAll();
        showError(model->lastError().text());
    } else {
        status->setText(tr("Удалено"));
    }
}

void MainWindow::refresh()
{
    if (!model->table().isEmpty()) {
        model->select();
        status->setText(tr("Обновлено"));
    }
}

void MainWindow::showError(const QString &msg)
{
    status->setText(msg);
    QMessageBox::critical(this, tr("Ошибка"), msg);
}