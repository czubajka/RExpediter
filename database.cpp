#include "database.h"
#include "mainwindow.h"

bool addMenuItem(int type_id, const QString &name, double price, const QString &description, int status)
{
    QSqlQuery query;
    query.prepare("INSERT INTO menu_item (type_id, name, price, description, status)"
                  "VALUES (:type_id, :name, :price, :description, :status)");
    query.addBindValue(++type_id);
    query.addBindValue(name);
    query.addBindValue(price);
    query.addBindValue(description);
    query.addBindValue(status+5);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Blad"),
                   QObject::tr("Nie udalo sie dodac pozycji do bazy.\n\n"), QMessageBox::Ok);
           qDebug() << "Database error : " << query.lastError();
           query.finish();
           return false;
       }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Dodano"),
                   QObject::tr("Produkt został pomyślnie dodany do bazy.\n\n"), QMessageBox::Ok);
        query.finish();
        return true;
    }
};


/*dodaje puste zamówienie do bazy, nie tworzy osobnego zamówienia w programie*/

int addOrder(int table_nr)
{
    //dodać tworzenie rachunku
    int table_order_id=-1;          

    QSqlQuery queryorder;
    queryorder.prepare("INSERT INTO table_order (table_nr, client_id)"
                  "VALUES (:table_nr, :client_id)");
    queryorder.addBindValue(table_nr);
    queryorder.addBindValue(0);      //oznacza zamowienie z sali

    if (!queryorder.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Blad"),
                   QObject::tr("Nie udalo sie dodac zamówienia.\n\n"), QMessageBox::Ok);
           qDebug() << "Database error : " << queryorder.lastError();
           queryorder.finish();
       }
    else
    {
        table_order_id = queryorder.lastInsertId().toInt();
        QMessageBox::information(nullptr, QObject::tr("Dodano"),
                   QObject::tr("Dodano zamówienie.\n\n"), QMessageBox::Ok);
        qDebug() << "Database error : " << queryorder.lastError();
        queryorder.finish();
    }

    return table_order_id;
}
