#include "menuitemform.h"
#include "ui_menuitemform.h"
#include "database.h"
#include <QInputDialog>
#include <QString>

MenuItemForm::MenuItemForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuItemForm)
{
    ui->setupUi(this);
}

MenuItemForm::~MenuItemForm()
{
    delete ui;
}


void MenuItemForm::on_buttonBox_accepted()
{
    addMenuItem(ui->comboBox->currentIndex(), ui->lineEdit->text() , ui->doubleSpinBox->value(), ui->plainTextEdit->toPlainText(), ui->comboBox_2->currentIndex());
    //buildMenu(DESER);
    //buildMenu(NAPOJ);
}

void MenuItemForm::on_buttonBox_rejected()
{
    QMessageBox::information(nullptr, QObject::tr("Anulowano"),
               QObject::tr("Produkt nie został dodany do bazy.\n\n"), QMessageBox::Ok);
}


