#include "database_manager.h"

DatabaseManager::DatabaseManager() : connected(false) {}

bool DatabaseManager::connect()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("kafe_sql");
    db.setUserName("postgres");
    db.setPassword("12345");
    
    if (db.open()) {
        connected = true;
        return true;
    } else {
        qDebug() << "Ошибка подключения:" << db.lastError().text();
        connected = false;
        return false;
    }
}

QSqlDatabase& DatabaseManager::getDatabase()
{
    return db;
}

bool DatabaseManager::isConnected() const
{
    return connected; 
}