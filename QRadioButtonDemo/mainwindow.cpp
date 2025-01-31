#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton_Human->isChecked())
    {
        if(ui->radioButton_cat->isChecked())
            QMessageBox::information(this,"Human Control","Yes you are human and cat");
        if(ui->radioButton_dog->isChecked())
            QMessageBox::information(this,"Human Control","Yes you are human and dog");
    }
    if(ui->radioButton_Monster->isChecked())
    {
        if(ui->radioButton_cat->isChecked())
            QMessageBox::information(this,"Monster Control","Yes you are monster and cat");
        if(ui->radioButton_dog->isChecked())
            QMessageBox::information(this,"Monster Control","Yes you are monster and dog");
    }
}

