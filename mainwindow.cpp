#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include "lwm2m.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    LWM2M onenet("xx1kjSUC5z1mRLr4buMMXDNH6Vg=");
    onenet.getDeviceByImei(this,"861931045659293");
    onenet.getDeviceByImei(this,"861931045459306");
}

MainWindow::~MainWindow()
{
    delete ui;
}

