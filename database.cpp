#include "database.h"

void addMenuItem(QSqlQuery &query, Type type_id, const QString &name, double price, const QString &description, Status status)
{

    //query.prepare("INSERT INTO menu_item (type_id, name, price, description, status)"
    //              "VALUES (:type_id, :name, :price, :description, :status)");
    query.addBindValue(type_id);
    query.addBindValue(name);
    query.addBindValue(price);
    query.addBindValue(description);
    query.addBindValue(status);
    query.exec();
};
