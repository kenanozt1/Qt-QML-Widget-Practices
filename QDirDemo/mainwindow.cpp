#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sayac(0)
{
    ui->setupUi(this);
    // QDir dir;
    // foreach (QFileInfo var, dir.drives()) {
    //     ui->comboBox->addItem(var.absoluteFilePath());
    // }
    QDir dir("C:/Users/Public/Documents");
    foreach (QFileInfo var, dir.entryInfoList()) {
        listDir(var.absoluteFilePath(),"combobox");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listDir(QString currentText, QString type)
{
    ui->listWidget->clear();
    QDir dir_2(currentText);
    foreach (QFileInfo var, dir_2.entryInfoList()) {
        if(type == "combobox"){
            if(var.isFile())
                ui->comboBox->addItem("File: "+var.absoluteFilePath());
            else
                ui->comboBox->addItem("Dir: "+var.absoluteFilePath());
        }else{
            if(var.isFile())
                ui->listWidget->addItem("File: "+var.absoluteFilePath());
            else
                ui->listWidget->addItem("Dir: "+var.absoluteFilePath());
        }
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    listDir(arg1.split(" ")[1],"listWidget");
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    listDir(item->text().split(" ")[1],"listWidget");
}

