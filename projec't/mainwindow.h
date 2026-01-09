// Главное окно CRUD-клиента PostgreSQL на Qt.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Виджеты и layout'ы
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QLineEdit>

// Валидация и вспомогательные типы
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMetaType>
#include <QVector>

// Сообщения и ошибки
#include <QMessageBox>

// Работа с БД
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
#include <QSqlError>

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