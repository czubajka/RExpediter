#ifndef ORDER_H
#define ORDER_H

enum Type : int {PRZYSTAWKA = 1, GLOWNE, DESER, DODATEK, NAPOJ, INNE};

#include <QVector>

class MenuItem
{
public:
    int menu_item_id;
    int type_id;
    QString name;
    double price;
    QString description;
    int status;

    MenuItem (int mi, int type, QString n, double p, QString d, int s)
        : menu_item_id{mi}, type_id{type}, name{n}, price{p}, description{d}, status{s}
    {}

};

class Order
{
private:
    int order_nr;
    int table_nr;
    int bill_id;
    bool bill;
    //Vector <Order_element> * order_elements;
public:

    Order(int order_id, int table)
    {
        order_nr = order_id;
        table_nr = table;
    }

    //QString showOrder()
    //{
    //    return
    //}
};

class Order_element
{
private:
    int item_id;
    int status;
    int item_type;
    int quantity;
    Order * order;

}
;

#endif // ORDER_H
