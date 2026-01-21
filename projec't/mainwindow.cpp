#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    // Подключаемся к базе данных
    dbManager.connect();
    
    // Только если подключение успешно
    if (dbManager.isConnected()) {
        QSqlDatabase& db = dbManager.getDatabase();
        
        // Создаем модель
        QSqlTableModel* model = new QSqlTableModel(this, db);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        
        // Настраиваем контроллер
        controller.setModel(model);
        controller.setDatabase(db);
        
        setupUi();
        
        // Загружаем список таблиц
        QSqlQuery q("SELECT table_name FROM information_schema.tables WHERE table_schema='public'", db);
        while (q.next()) tables->addItem(q.value(0).toString());
        
        if (tables->count()) {
            changeTable();
        }
    } else {
        // Если нет подключения, все равно создаем UI (для отладки)
        setupUi();
        QMessageBox::warning(this, "Ошибка", "Не удалось подключиться к базе данных");
    }
}

void MainWindow::setupUi()
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);
    
    QVBoxLayout* layout = new QVBoxLayout(central);
    
    QHBoxLayout* top = new QHBoxLayout();
    tables = new QComboBox();
    refreshBtn = new QPushButton("Обновить");
    addBtn = new QPushButton("Добавить");
    delBtn = new QPushButton("Удалить");
    
    top->addWidget(tables, 1);
    top->addWidget(refreshBtn);
    top->addWidget(addBtn);
    top->addWidget(delBtn);
    layout->addLayout(top);
    
    QHBoxLayout* reportLayout = new QHBoxLayout();
    stockBtn = new QPushButton("Склад");
    popularBtn = new QPushButton("Популярные");
    
    reportLayout->addWidget(stockBtn);
    reportLayout->addWidget(popularBtn);
    layout->addLayout(reportLayout);
    
    view = new QTableView();
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    controller.setView(view);
    controller.setTablesCombo(tables);
    
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
    controller.changeTable(tables->currentText());
}

void MainWindow::addRow()
{
    controller.addRow(tables->currentText());
}

void MainWindow::deleteRow()
{
    controller.deleteRow();
}

void MainWindow::refresh()
{
    controller.refresh();
}

void MainWindow::showStockReport()
{
    QString report = controller.getStockReportData();
    QMessageBox::information(this, "Склад", report);
}

void MainWindow::showPopularReport()
{
    QString report = controller.getPopularReportData();
    QMessageBox::information(this, "Популярные блюда", report);
}