#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtGui>
#include <QtCore>
#include "database.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addMenuItemButton_clicked();

    void on_pushButton_clicked();

    void buildMenu();

    void on_deleteMenuItemButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model_glowne;
    QSqlTableModel *model_przystawki;
    QSqlTableModel *model_desery;
    QSqlTableModel *model_napoje;
    QSqlTableModel *model_dodatki;
    QSqlTableModel *model_inne;
};

#endif // MAINWINDOW_H
