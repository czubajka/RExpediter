#include "order.h"
#include <QVector>

class MenuItem
{

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
