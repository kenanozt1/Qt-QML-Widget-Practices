#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *newItem = new QListWidgetItem(QIcon(":/img/exit.png"),"Mark");
    ui->listWidget->addItem(newItem);
    QListWidgetItem *newItem2 = new QListWidgetItem(QIcon(":/img/new.png"),"Micheal");
    ui->listWidget->addItem(newItem2);
    QListWidgetItem *newItem3 = new QListWidgetItem(QIcon(":/img/open.png"),"Adam");
    ui->listWidget->addItem(newItem3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); i++) {
        ui->listWidget->item(i)->setBackgroundColor(Qt::white);
        ui->listWidget->item(i)->setForeground(Qt::black);
    }
    ui->listWidget->currentItem()->setBackgroundColor(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}

