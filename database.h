#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QtSql>
#include <iostream>
#include <QMessageBox>

enum Type : int {PRZYSTAWKA = 1, GLOWNE, DESER, DODATEK, NAPOJ, INNE};
enum Status : int {ZAMOWIONE = 1, WYWOLANE, WYDANE, ANULOWANE, DOSTEPNE, NIEDOSTEPNE, OPLACONE, NIEOPLACONE };

bool addMenuItem(int type_id, const QString &name, double price, const QString &description, int status);

bool buildMenu(Type type);

#endif // DATABASE_H
