#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), model(nullptr)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("kafe_sql");
    db.setUserName("postgres");
    db.setPassword("12345");
    
    if (!db.open()) {
        qDebug() << "Ошибка подключения:" << db.lastError().text();
        return;
    }
    
    model = new QSqlTableModel(this, db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    setupUi();
    
    QSqlQuery q("SELECT table_name FROM information_schema.tables WHERE table_schema='public'", db);
    while (q.next()) tables->addItem(q.value(0).toString());
    if (tables->count()) changeTable();
}

void MainWindow::setupUi()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);
    
    auto *top = new QHBoxLayout();
    tables = new QComboBox();
    refreshBtn = new QPushButton("Обновить");
    addBtn = new QPushButton("Добавить");
    delBtn = new QPushButton("Удалить");
    
    top->addWidget(tables, 1);
    top->addWidget(refreshBtn);
    top->addWidget(addBtn);
    top->addWidget(delBtn);
    layout->addLayout(top);
    
    view = new QTableView();
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    layout->addWidget(view);
    
    setCentralWidget(central);
    resize(900, 600);
    
    connect(tables, &QComboBox::currentTextChanged, this, &MainWindow::changeTable);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refresh);
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::deleteRow);
}

void MainWindow::changeTable()
{
    QString table = tables->currentText();
    if (table.isEmpty()) return;
    
    model->setTable(table);
    model->select();
    view->resizeColumnsToContents();
}

void MainWindow::addRow()
{
    // Вставляем новую строку
    int row = model->rowCount();
    model->insertRow(row);
    
    QString tableName = tables->currentText();
    
    if (tableName == "zakazy") {
        // Получаем текущее время в американском формате
        QString currentTime = QDateTime::currentDateTime().toString("M/d/yy h:mm AP");
        model->setData(model->index(row, 0), currentTime);
    }
    else if (tableName == "sostav_zakaza") {
        // Получаем последнее время заказа для удобства
        QSqlQuery query(db);
        query.exec("SELECT vremya_zakaza FROM zakazy ORDER BY vremya_zakaza DESC LIMIT 1");
        if (query.next()) {
            QString lastOrderTime = query.value(0).toString();
            model->setData(model->index(row, 0), lastOrderTime);
        }
        // Устанавливаем количество по умолчанию
        if (model->columnCount() > 2) {
            model->setData(model->index(row, 2), 1);
        }
    }
    
    // Переходим к новой строке
    QModelIndex index = model->index(row, 0);
    view->setCurrentIndex(index);
    view->scrollTo(index);
}

void MainWindow::deleteRow()
{
    QModelIndex index = view->currentIndex();
    if (index.isValid()) {
        model->removeRow(index.row());
    }
}

void MainWindow::refresh()
{
    // Пытаемся сохранить изменения
    if (!model->submitAll()) {
        // Показываем простое сообщение об ошибке
        QMessageBox::warning(this, "Ошибка", 
            "Не удалось сохранить изменения.\n"
            "Возможные причины:\n"
            "1. Не заполнены обязательные поля\n"
            "2. Нарушение внешних ключей\n"
            "3. Неверный формат данных");
    }
    
    // В любом случае обновляем таблицу
    model->select();
}