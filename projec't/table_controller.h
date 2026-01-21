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
    
    // Установка компонентов
    void setModel(QSqlTableModel* model);
    void setView(QTableView* view);
    void setTablesCombo(QComboBox* combo);
    void setDatabase(QSqlDatabase& db);
    
    // Основные операции с таблицей
    void changeTable(const QString& tableName);
    void addRow(const QString& currentTable);
    void deleteRow();
    void refresh();
    
    // Методы для получения данных (без UI)
    QString getStockReportData();
    QString getPopularReportData();
    
    // Геттер для модели
    QSqlTableModel* getModel() const { return model; }
    
private:
    QSqlTableModel* model;
    QTableView* view;
    QComboBox* tablesCombo;
    QSqlDatabase* db;
};

#endif