#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/login_icon.png");
    int w = ui->label_pix->width();
    int h = ui->label_pix->height();
    ui->label_pix->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->statusbar->addPermanentWidget(ui->label_5,1);
    ui->statusbar->addPermanentWidget(ui->progressBar,5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEdit_2->text();

    if(username == "test" && password == "test"){
        // QMessageBox::information(this,"Login","Username and password is correct");
        // hide();
        // secDialog = new SecDialog();
        // secDialog->show();

        ui->statusbar->showMessage("Username and password is correct",5000);
        ui->label_5->setText("Username and password is correct");
    }else{
        ui->statusbar->showMessage("Username and password is not correct",5000);
        ui->label_5->setText("Username and password is not correct");
        // QMessageBox::warning(this,"Login","Username and password is not correct");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEditUsername->clear();
    ui->lineEdit_2->clear();
}

