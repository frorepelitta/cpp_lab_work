#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database_manager.h"
#include "table_controller.h"
#include <QMainWindow>
#include <QComboBox>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>   
#include <QDebug> 

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    bool isReady() const { return dbManager.isConnected(); }

private slots:
    void changeTable();
    void addRow();
    void deleteRow();
    void refresh();
    void showStockReport();
    void showPopularReport();

private:
    void setupUi();
    
    DatabaseManager dbManager;
    TableController controller;
    
    QComboBox* tables;
    QTableView* view;
    QPushButton *addBtn, *delBtn, *refreshBtn, *stockBtn, *popularBtn;
};

#endif