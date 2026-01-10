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
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    
    QVBoxLayout *layout = new QVBoxLayout(central);
    
    QHBoxLayout *top = new QHBoxLayout();
    tables = new QComboBox();
    refreshBtn = new QPushButton("Обновить");
    addBtn = new QPushButton("Добавить");
    delBtn = new QPushButton("Удалить");
    
    top->addWidget(tables, 1);
    top->addWidget(refreshBtn);
    top->addWidget(addBtn);
    top->addWidget(delBtn);
    layout->addLayout(top);
    
    QHBoxLayout *reportLayout = new QHBoxLayout();
    QPushButton *stockBtn = new QPushButton("Склад");
    QPushButton *popularBtn = new QPushButton("Популярные");
    
    reportLayout->addWidget(stockBtn);
    reportLayout->addWidget(popularBtn);
    layout->addLayout(reportLayout);
    
    view = new QTableView();
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    layout->addWidget(view);
    
    resize(900, 600);
    
    connect(tables, &QComboBox::currentTextChanged, this, &MainWindow::changeTable);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refresh);
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::deleteRow);
    connect(stockBtn, &QPushButton::clicked, this, &MainWindow::showStockReport);
    connect(popularBtn, &QPushButton::clicked, this, &MainWindow::showPopularReport);
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
    int row = model->rowCount();
    model->insertRow(row);
    
    QString tableName = tables->currentText();
    
    if (tableName == "zakazy") {
        model->setData(model->index(row, 0), QDateTime::currentDateTime().toString("M/d/yy h:mm AP"));
    }
    else if (tableName == "sostav_zakaza") {
        QSqlQuery q(db);
        q.exec("SELECT vremya_zakaza FROM zakazy ORDER BY vremya_zakaza DESC LIMIT 1");
        if (q.next()) model->setData(model->index(row, 0), q.value(0).toString());
        if (model->columnCount() > 2) model->setData(model->index(row, 2), 1);
    }
    
    view->setCurrentIndex(model->index(row, 0));
    view->scrollTo(model->index(row, 0));
}

void MainWindow::deleteRow()
{
    QModelIndex index = view->currentIndex();
    if (index.isValid()) model->removeRow(index.row());
}

void MainWindow::refresh()
{
    if (!model->submitAll()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить изменения");
    }
    model->select();
}

// Отчет 1: Остатки на складе
void MainWindow::showStockReport()
{
    QSqlQuery q(db);
    q.exec("SELECT nazvanie_ingredienta, ostatok, mera_izmereniya FROM sklad");
    
    QString report;
    while (q.next()) {
        report += q.value(0).toString() + ": " + 
                 q.value(1).toString() + " " + 
                 q.value(2).toString() + "\n";
    }
    
    QMessageBox::information(this, "Склад", report);
}

// Отчет 2: Популярные блюда (упрощенный)
void MainWindow::showPopularReport()
{
    QSqlQuery q(db);
    q.exec("SELECT pm.nazvanie_pozitsii, SUM(sz.kolichestvo) "
           "FROM sostav_zakaza sz "
           "JOIN pozitsii_menyu pm ON sz.nazvanie_pozitsii = pm.nazvanie_pozitsii "
           "GROUP BY pm.nazvanie_pozitsii ORDER BY SUM(sz.kolichestvo) DESC");
    
    QString report;
    int i = 1;
    while (q.next()) {
        report += QString("%1. %2: %3\n").arg(i).arg(q.value(0).toString()).arg(q.value(1).toInt());
        i++;
    }
    
    QMessageBox::information(this, "Популярные блюда", report);
}