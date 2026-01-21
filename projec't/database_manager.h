#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager
{
public:
    DatabaseManager();
    bool connect();
    QSqlDatabase& getDatabase();
    bool isConnected() const; 
    
private:
    QSqlDatabase db;
    bool connected;
};

#endif