#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuitemform.h"
#include "orderform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("default");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("rexpeditor");
    db.setUserName("root");
    db.setPassword("Q188q199");

    if (!db.open())
        {
            std::cout << "Database failed to open." << std::endl;
            qDebug() << db.lastError();
            QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                       QObject::tr("Nie udalo sie polaczyc z baza danych.\n"
                                   "Sprawdz poprawnosc danych logowania do bazy i czy baza uzywa szyfrowanych hasel.\n"
                                   "Wylacz w bazie szyfrowanie hasla dla tej aplikacji.\n"
                                   "Ta aplikacja wymaga sterownika QMySQL.\n\n"), QMessageBox::Cancel);
        }
    else
        {
           std::cout << "Database is now opened"<< std::endl;

           model = new QSqlRelationalTableModel(this);
           model->setTable("menu_item");
           model->setRelation(0, QSqlRelation("item_type", "type_id", "type_id"));
           model->select();

           ui->tableView->setModel(model);

           //sqlTableModel

           tableModel = new QSqlTableModel(this);
           tableModel->setTable("menu_item");
           tableModel->select();

           ui->tableView_2->setModel(tableModel);

        }
}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase db = QSqlDatabase::database();         //static func QSqlDatabase::database() returns a pointer to the default (or given as param) database
    db.close();
    db.removeDatabase("default");
    if(!db.isOpen())
        std::cout << "Database connection closed" << std::endl;
}

void MainWindow::on_addMenuItemButton_clicked()
{
    MenuItemForm mif;
    mif.setModal(true);
    mif.exec();
}


