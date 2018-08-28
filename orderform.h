#ifndef ORDERFORM_H
#define ORDERFORM_H

#include <QDialog>

namespace Ui {
class OrderForm;
}

class OrderForm : public QDialog
{
    Q_OBJECT

public:
    explicit OrderForm(QWidget *parent = nullptr);
    ~OrderForm();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::OrderForm *ui;
};

#endif // ORDERFORM_H
