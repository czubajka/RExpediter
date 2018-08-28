#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QtSql>
#include <iostream>
#include <QMessageBox>

enum Type : unsigned char {PRZYSTAWKA = 1, GLOWNE, DESER, DODATEK, NAPOJ, INNE};
enum Status : unsigned char {ZAMOWIONE = 1, WYWOLANE, WYDANE, ANULOWANE, DOSTEPNE, NIEDOSTEPNE, OPLACONE, NIEOPLACONE };

bool addMenuItem(Type type_id, const QString &name, double price, const QString &description, Status status);

static bool connectToDatabase()
{

        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("default");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setDatabaseName("rexpeditor");
        db.setUserName("root");
        db.setPassword("Q188q199");

    if (!db.open())
    {
        std::cout << "Database failed to open." << std::endl;
        qDebug() << db.lastError();
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                   QObject::tr("Nie udalo sie polaczyc z baza danych.\n"
                               "Sprawdz poprawnosc danych logowania do bazy i czy baza uzywa szyfrowanych hasel.\n"
                               "Wylacz w bazie szyfrowanie hasla dla tej aplikacji.\n"
                               "Ta aplikacja wymaga sterownika QMySQL.\n\n"), QMessageBox::Cancel);
        return false;
    }
    else
    {
       std::cout << "Database is now opened"<< std::endl;
       return true;
    }
}

static bool closeConnection()
{
    QSqlDatabase db = QSqlDatabase::database();         //static func QSqlDatabase::database() returns a pointer to the default (or given as param) database
    db.close();
    db.removeDatabase("default");
    if(!db.isOpen())
        std::cout << "Database connection closed" << std::endl;
    return true;
};


bool buildMenu(Type type);

#endif // DATABASE_H
