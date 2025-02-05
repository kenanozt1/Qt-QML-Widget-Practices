#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,timer(new QTimer(this))
{
    ui->setupUi(this);
    // timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myFunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::myFunction()
{
    QTime time = QTime::currentTime();
    QString textTime = time.toString("hh:mm:ss");
    ui->label->setText(textTime);
}
