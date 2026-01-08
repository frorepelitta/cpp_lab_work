// Главное окно CRUD-клиента PostgreSQL на Qt.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    bool isReady() const { return ready; }

private slots:
    void changeTable(const QString &table);
    void addRow();
    void editRow();
    void deleteRow();
    void refresh();

private:
    bool setupDb();
    void setupUi();
    void loadTables();
    bool editRecord(QSqlRecord &rec, const QString &title);
    void showError(const QString &msg);

    QSqlDatabase db;
    QSqlTableModel *model{nullptr};
    QComboBox *tables{nullptr};
    QTableView *view{nullptr};
    QLabel *status{nullptr};
    QPushButton *addBtn{nullptr};
    QPushButton *editBtn{nullptr};
    QPushButton *delBtn{nullptr};
    QPushButton *refreshBtn{nullptr};
    bool ready{false};
};

#endif // MAINWINDOW_H