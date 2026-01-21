#include "table_controller.h"

TableController::TableController(QObject* parent) : 
    QObject(parent), model(nullptr), view(nullptr), 
    tablesCombo(nullptr), db(nullptr) {}

void TableController::setModel(QSqlTableModel* newModel)
{
    model = newModel;
    if (view) {
        view->setModel(model);
    }
}

void TableController::setView(QTableView* newView)
{
    view = newView;
    if (view && model) {
        view->setModel(model);
    }
}

void TableController::setTablesCombo(QComboBox* combo)
{
    tablesCombo = combo;
}

void TableController::setDatabase(QSqlDatabase& database)
{
    db = &database;
}

void TableController::changeTable(const QString& tableName)
{
    if (tableName.isEmpty() || !model || !db) return;
    
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    
    if (view) {
        view->resizeColumnsToContents();
    }
}

void TableController::addRow(const QString& currentTable)
{
    if (!model || !view) return;
     
    int row = model->rowCount();
    model->insertRow(row);
    
    if (currentTable == "zakazy") {
        model->setData(model->index(row, 0), QDateTime::currentDateTime().toString("M/d/yy h:mm AP"));
    }
    else if (currentTable == "sostav_zakaza" && db) {
        QSqlQuery q(*db);
        q.exec("SELECT vremya_zakaza FROM zakazy ORDER BY vremya_zakaza DESC LIMIT 1");
        if (q.next()) model->setData(model->index(row, 0), q.value(0).toString());
        if (model->columnCount() > 2) model->setData(model->index(row, 2), 1);
    }
    
    view->setCurrentIndex(model->index(row, 0));
    view->scrollTo(model->index(row, 0));
}

void TableController::deleteRow()
{
    if (!model || !view) return;
    
    QModelIndex index = view->currentIndex();
    if (index.isValid()) model->removeRow(index.row());
}

void TableController::refresh()
{
    if (!model) return;
    
    if (!model->submitAll()) {
        QMessageBox::warning(nullptr, "Ошибка", "Не удалось сохранить изменения");
    }
    model->select();
}

QString TableController::getStockReportData()
{
    if (!db) return "Database not connected";
    
    QSqlQuery q(*db);
    q.exec("SELECT nazvanie_ingredienta, ostatok, mera_izmereniya FROM sklad");
    
    QString report;
    while (q.next()) {
        report += q.value(0).toString() + ": " + 
                 q.value(1).toString() + " " + 
                 q.value(2).toString() + "\n";
    }
    
    return report;
}

QString TableController::getPopularReportData()
{
    if (!db) return "Database not connected";
    
    QSqlQuery q(*db);
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
    
    return report;
}