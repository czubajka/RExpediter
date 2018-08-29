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

           //sqlTableModel

           model_glowne = new QSqlTableModel(this);
           model_glowne->setTable("menu_item");
           model_glowne->setFilter(QString("type_id = %1").arg(GLOWNE));
           model_glowne->select();
           ui->tableView->setModel(model_glowne);

           model_przystawki = new QSqlTableModel(this);
           model_przystawki->setTable("menu_item");
           model_przystawki->setFilter(QString("type_id = %1").arg(PRZYSTAWKA));
           model_przystawki->select();
           ui->tableView_2->setModel(model_przystawki);

           model_desery = new QSqlTableModel(this);
           model_desery->setTable("menu_item");
           model_desery->setFilter(QString("type_id = %1").arg(DESER));
           model_desery->select();
           ui->tableView_3->setModel(model_desery);

           model_dodatki = new QSqlTableModel(this);
           model_dodatki->setTable("menu_item");
           model_dodatki->setFilter(QString("type_id = %1").arg(DODATEK));
           model_dodatki->select();
           ui->tableView_4->setModel(model_dodatki);

           model_napoje = new QSqlTableModel(this);
           model_napoje->setTable("menu_item");
           model_napoje->setFilter(QString("type_id = %1").arg(NAPOJ));
           model_napoje->select();
           ui->tableView_5->setModel(model_napoje);

           model_inne = new QSqlTableModel(this);
           model_inne->setTable("menu_item");
           model_inne->setFilter(QString("type_id = %1").arg(INNE));
           model_inne->select();
           ui->tableView_6->setModel(model_inne);

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


