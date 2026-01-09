#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    bool isReady() { return db.isOpen(); }

private slots:
    void changeTable();
    void addRow();
    void deleteRow();
    void refresh();

private:
    void setupUi();
    
    QSqlDatabase db;
    QSqlTableModel *model;
    QComboBox *tables;
    QTableView *view;
    QPushButton *addBtn, *delBtn, *refreshBtn;
};

#endif