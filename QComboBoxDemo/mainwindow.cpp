#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 10; i++){
        ui->comboBox->addItem(QIcon(":/resource/img/exit.png"),QString::number(i));
    }
    ui->comboBox->insertItem(3,QIcon(":/resource/img/new.png"),QString::number(3));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Combobox title",ui->comboBox->currentText());
}

