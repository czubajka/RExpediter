#include "mainwindow.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if (!connectToDatabase())
        return 1;

    addMenuItem(DESER, "Ciasteczko matcha", 22.90, "ciastko bezglutenowe ze sproszkowana herbata matcha", NIEDOSTEPNE);
    buildMenu(DESER);
    buildMenu(NAPOJ);
    return a.exec();
}
