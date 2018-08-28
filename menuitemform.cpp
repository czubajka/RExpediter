#include "menuitemform.h"
#include "ui_menuitemform.h"
#include "database.h"

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
    addMenuItem(DESER, "Ciasteczko matcha", 22.90, "ciastko bezglutenowe ze sproszkowana herbata matcha", NIEDOSTEPNE);
    //buildMenu(DESER);
    //buildMenu(NAPOJ);
}

void MenuItemForm::on_buttonBox_rejected()
{
    QMessageBox::information(nullptr, QObject::tr("Anulowano"),
               QObject::tr("Produkt nie został dodany do bazy.\n\n"), QMessageBox::Ok);
}
