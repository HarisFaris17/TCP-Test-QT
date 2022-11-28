#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpServer(new TcpServer())
{
    ui->setupUi(this);
    tcpServer->setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}
