#include "orderform.h"
#include "ui_orderform.h"

OrderForm::OrderForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderForm)
{
    ui->setupUi(this);
}

OrderForm::~OrderForm()
{
    delete ui;
}

void OrderForm::on_buttonBox_accepted()
{
    OrderForm of;
    of.setModal(true);
}
