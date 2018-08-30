#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtGui>
#include <QtCore>
#include "database.h"
#include "order.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;

private slots:

    void on_addMenuItemButton_clicked();

    void on_pushButton_clicked();

    void buildMenu();

    bool buildOrders();

    void on_deleteMenuItemButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString ordersString;
    QSqlTableModel *model_glowne;
    QSqlTableModel *model_przystawki;
    QSqlTableModel *model_desery;
    QSqlTableModel *model_napoje;
    QSqlTableModel *model_dodatki;
    QSqlTableModel *model_inne;
    QVector<Order> *orders;
    QVector<MenuItem> * items;


};

#endif // MAINWINDOW_H
