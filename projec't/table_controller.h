#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H

#include <QObject>
#include <QSqlTableModel>
#include <QTableView>
#include <QComboBox>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include <QSqlError> 
#include <QDebug>     

class TableController : public QObject
{
    Q_OBJECT
public:
    explicit TableController(QObject* parent = nullptr);
    
    void setModel(QSqlTableModel* model);
    void setView(QTableView* view);
    void setTablesCombo(QComboBox* combo);
    void setDatabase(QSqlDatabase& db);
    
    void changeTable(const QString& tableName);
    void addRow(const QString& currentTable);
    void deleteRow();
    void refresh();
    
    QString getStockReportData();
    QString getPopularReportData();
    
    QSqlTableModel* getModel() const { return model; }
    
private:
    QSqlTableModel* model;
    QTableView* view;
    QComboBox* tablesCombo;
    QSqlDatabase* db;
};

#endif