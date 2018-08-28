#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuitemform.h"
#include "orderform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    closeConnection();
}

void MainWindow::on_addMenuItemButton_clicked()
{
    MenuItemForm mif;
    mif.setModal(true);
    mif.exec();
}


