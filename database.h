#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QtSql>
#include <iostream>
#include <QMessageBox>

enum Type : unsigned char {PRZYSTAWKA = 1, GLOWNE, DESER, DODATEK, NAPOJ, INNE};
enum Status : unsigned char {ZAMOWIONE = 1, WYWOLANE, WYDANE, ANULOWANE, DOSTEPNE, NIEDOSTEPNE, OPLACONE, NIEOPLACONE };

bool addMenuItem(Type type_id, const QString &name, double price, const QString &description, Status status);


//static bool connectToDatabase()
//{

//        QSqlDatabase db;

//}

//static bool closeConnection()
//{

//    return true;
//};


bool buildMenu(Type type);

#endif // DATABASE_H
