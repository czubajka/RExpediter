#include "database.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QSqlError>

bool connectToDatabase()
{
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setDatabaseName("rexpeditor");
        db.setUserName("root");
        db.setPassword("Q188q199");
        bool ok = db.open();
        db.lastError();
        if (db.isOpen()) std::cout << "open" << std::endl;
        if (db.isValid()) std::cout << "valid" << std::endl;

        if (db.lastError().isValid())
            qDebug() << db.lastError();

    if (ok)
    {
        std::cout <<"true"<< std::endl;
        return true;
    }
    else
    {
       std::cout << "false"<< std::endl;
        return false;
    }
}

bool closeConnection()
{
    return true;
};
