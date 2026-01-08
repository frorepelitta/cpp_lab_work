// Простое клиент-серверное Qt-приложение для CRUD с PostgreSQL.
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if (!w.isReady()) {
        return 1; // подключение к БД не удалось
    }
    w.show();
    return a.exec();
}