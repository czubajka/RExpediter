#include "database.h"

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
           return false;
       }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Dodano"),
                   QObject::tr("Produkt został pomyślnie dodany do bazy.\n\n"), QMessageBox::Ok);
           return true;
    }
};

bool buildMenu(Type type)
{
    QSqlQuery query;
    query.prepare("SELECT name, price, description, status FROM menu_item "
                  "WHERE type_id=?");
    query.bindValue(0, type);

    if (!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }
    else
    {
        while(query.next())
        {
            QString name = query.value(0).toString();
            double price = query.value(1).toDouble();
            QString description = query.value(2).toString();
            int status = query.value(3).toInt();

            qDebug() << "/n/n"
                         "- " + name + ", cena: " + price + "/n"
                         + description + ", STATUS: " + status;
        }
       return true;
    }
};
