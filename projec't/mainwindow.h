#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QHeaderView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    bool isReady() { return ready; }

private slots:
    void changeTable();
    void addRow();
    void editRow();
    void deleteRow();
    void refresh();

private:
    void setupUi();
    
    QSqlDatabase db;
    QSqlTableModel *model;
    QComboBox *tables;
    QTableView *view;
    QPushButton *refreshBtn, *addBtn, *editBtn, *delBtn;
    QLabel *status;
    bool ready;
};

#endif