#include "order.h"
#include <Vector>

class Order
{
private:
    int order_nr;
    int table_nr;
    int bill_id;
    bool bill;
    //Vector <Order_element> * order_elements;
public:
    Order();

    Order * createNewOrder();
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
