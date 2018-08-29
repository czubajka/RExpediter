#ifndef MENUITEMFORM_H
#define MENUITEMFORM_H

#include <QDialog>

namespace Ui {
    class MenuItemForm;
}

class MenuItemForm : public QDialog
{
    Q_OBJECT

public:
    explicit MenuItemForm(QWidget *parent = nullptr);
    ~MenuItemForm();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::MenuItemForm *ui;
};

#endif // MENUITEMFORM_H

