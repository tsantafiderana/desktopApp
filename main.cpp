#include "mainwindow.h"
#include "dashboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Créer et afficher le Dashboard
    Dashboard dashboard;
    dashboard.setWindowTitle("Hotel Management System - Dashboard");
    dashboard.show();

    return a.exec();
}
