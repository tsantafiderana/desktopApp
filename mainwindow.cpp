#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dashboard(nullptr)
{
    ui->setupUi(this);
}


void MainWindow::on_btnSubmit_clicked()
{
    this->hide();
    if(dashboard == nullptr) {
        dashboard = new Dashboard;
    }

    dashboard->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dashboard;
}


