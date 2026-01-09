#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), model(nullptr)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("kafe_sql");
    db.setUserName("postgres");
    db.setPassword("12345");
    
    ready = db.open();
    if (ready) {
        model = new QSqlTableModel(this, db);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        setupUi();
        
        QSqlQuery q("SELECT table_name FROM information_schema.tables WHERE table_schema='public'", db);
        while (q.next()) tables->addItem(q.value(0).toString());
        if (tables->count()) changeTable();
    }
}

void MainWindow::setupUi()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);
    
    auto *top = new QHBoxLayout();
    tables = new QComboBox();
    refreshBtn = new QPushButton("Обновить");
    addBtn = new QPushButton("Добавить");
    editBtn = new QPushButton("Изменить");
    delBtn = new QPushButton("Удалить");
    
    top->addWidget(tables, 1);
    top->addWidget(refreshBtn);
    top->addWidget(addBtn);
    top->addWidget(editBtn);
    top->addWidget(delBtn);
    layout->addLayout(top);
    
    view = new QTableView();
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    layout->addWidget(view, 1);
    
    status = new QLabel("Готово");
    layout->addWidget(status);
    
    setCentralWidget(central);
    resize(900, 600);
    
    connect(tables, &QComboBox::currentTextChanged, this, &MainWindow::changeTable);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refresh);
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(editBtn, &QPushButton::clicked, this, &MainWindow::editRow);
    connect(delBtn, &QPushButton::clicked, this, &MainWindow::deleteRow);
}

void MainWindow::changeTable()
{
    QString table = tables->currentText();
    if (table.isEmpty()) return;
    
    model->setTable(table);
    model->select();
    view->resizeColumnsToContents();
    status->setText("Таблица: " + table);
}

void MainWindow::addRow()
{
    if (model->insertRow(model->rowCount())) {
        QModelIndex index = model->index(model->rowCount() - 1, 0);
        view->setCurrentIndex(index);
        view->edit(index);
    }
}

void MainWindow::editRow()
{
    QModelIndex index = view->currentIndex();
    if (index.isValid()) {
        view->edit(index);
    }
}

void MainWindow::deleteRow()
{
    QModelIndex index = view->currentIndex();
    if (!index.isValid()) return;
    
    if (QMessageBox::question(this, "Удалить", "Удалить выбранную строку?") == QMessageBox::Yes) {
        model->removeRow(index.row());
        model->submitAll();
    }
}

void MainWindow::refresh()
{
    model->select();
    status->setText("Обновлено");
}