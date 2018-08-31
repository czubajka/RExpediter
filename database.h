#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QtSql>
#include <QMessageBox>
#include "order.h"

enum Status : int {ZAMOWIONE = 1, WYWOLANE, WYDANE, ANULOWANE, DOSTEPNE, NIEDOSTEPNE, OPLACONE, NIEOPLACONE };

bool addMenuItem(int type_id, const QString &name, double price, const QString &description, int status);
int addOrder(int);

#endif // DATABASE_H
