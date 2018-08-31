#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menuitemform.h"
#include <QInputDialog>
#include "order.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->order_result->setText(" ");

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("default");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("rexpediter");
    db.setUserName("root");
    db.setPassword("Q188q199");

    if (!db.open())
        {
            qDebug() << db.lastError();
            QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                       QObject::tr("Nie udalo sie polaczyc z baza danych.\n"
                                   "Sprawdz poprawnosc danych logowania do bazy i czy baza uzywa szyfrowanych hasel.\n"
                                   "Wylacz w bazie szyfrowanie hasla dla tej aplikacji.\n"
                                   "Ta aplikacja wymaga sterownika QMySQL.\n\n"), QMessageBox::Cancel);
        }
    else
        {
          buildMenu();
        }

    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(orderButtonClicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase db = QSqlDatabase::database();         //static func QSqlDatabase::database() returns a pointer to the default (or given as param) database
    db.close();
    db.removeDatabase("default");
    delete signalMapper;
}

void MainWindow::on_addMenuItemButton_clicked()
{
    MenuItemForm mif;
    mif.setModal(true);
    mif.exec();
    db.commit();
}

void MainWindow::on_pushButton_clicked()
{
    int n = QInputDialog::getInt(this, "Stolik", "Podaj nr stolika:");
    n = addOrder(n);
    db.commit();
    buildOrders();
    db.commit();
}

void MainWindow::buildMenu()
{
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
    ui->tableView_6->setModel(model_napoje);

    model_inne = new QSqlTableModel(this);
    model_inne->setTable("menu_item");
    model_inne->setFilter(QString("type_id = %1").arg(INNE));
    model_inne->select();
    ui->tableView_5->setModel(model_inne);

};

bool MainWindow::buildOrders()
{
        QSqlQuery query;
        QString result = "";

//        qDeleteAll(ui->buttonsSpace->children());       //cleans buttons
//        QLayoutItem *child;
//        while ((child = ui->buttonsSpace->takeAt(0)) != nullptr) {
//            ui->buttonsSpace->removeItem(ui->buttonsSpace->takeAt(0));
//            delete child->widget();
//        }
        clearLayout(ui->buttonsSpace);

        query.prepare("SELECT order_id, table_nr, client_id FROM table_order");
        if (!query.exec())
        {
            qDebug() << query.lastError();
            query.finish();
            return false;
        }
        else
        {
            while(query.next())
            {
                //make button

                QPushButton * a = new QPushButton();
                ui->buttonsSpace->addWidget(a);
                a->setText("Zamówienie: " + query.value(0).toString());
                connect(a, SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(a, query.value(0).toInt());

                //end make button

                result +=  "<b>Zamówienie nr: </b> ";

                int order_id = query.value(0).toInt();
                result += QString::number(order_id);

                int table = query.value(1).toInt();
                result +=  "<br><b>stolik : </b> ";
                result += QString::number(table);

                int client_id = query.value(2).toInt();

                if (client_id == 0)
                {
                    result += "<br> +++ zamówienie z sali +++<br><br>";
                }
                else
                {
                    result +=  "<br> +++ zamówienie online +++ <br><br>";
                }

                //elementy zamówienia



            }
           ui->order_result->setText(result);
           query.finish();
           return true;
        }
}

void MainWindow::buildItems(/*std::vector <MenuItem>& v*/)
{
    items.clear();
    QSqlQuery query;
    query.prepare("SELECT menu_item_id, type_id, name, price, description, status FROM menu_item");
    if (!query.exec())
    {
        qDebug() << query.lastError();
        query.finish();
    }
    else
    {
        while(query.next())
        {
            items.push_back(*new MenuItem(query.value(0).toInt(), query.value(1).toInt(), query.value(2).toString(), query.value(3).toDouble(), query.value(4).toString(), query.value(5).toInt()));
        }
        query.finish();
    }
    qDebug() << "W menu znajduje sie" << QString::number(items.size()) << "elementów";
}

void MainWindow::readItems()
{
   qDebug() << items.size() << " elementów    ";
   for (auto item: items)
   {
       qDebug() << "nazwa: " << item.name << ", ID: " << item.menu_item_id << ", cena: " << item.price;
   }

}

void MainWindow::readFullOrders()
{
    ordersString = "";

    ui->order_result->setText(ordersString);
}


void MainWindow::on_deleteMenuItemButton_clicked()
{
    buildMenu();
    db.commit();
    buildItems();
    db.commit();
    readItems();    //for debug
}

void MainWindow::on_pushButton_2_clicked()
{
    buildOrders();
    db.commit();
}

 void MainWindow::orderButtonClicked(int id)
 {
     qDebug() << id;
 }

 void MainWindow::clearLayout(QLayout *layout)
 {
     QLayoutItem *child;
     while ((child = layout->takeAt(0)) != 0) {
     if(child->layout() != 0)
     clearLayout( child->layout() );
     else if(child->widget() != 0)
     delete child->widget();

         delete child;
 }
 };
