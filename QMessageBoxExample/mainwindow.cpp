#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
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
    // QMessageBox::about(this,"MY Title","My Message");
    // QMessageBox::aboutQt(this,"MY Title");
    // QMessageBox::critical(this,"MY Title","My Message","Ok","Cancel");
    // QMessageBox::information(this,"MY Title","My Message");
    // QMessageBox::warning(this,"MY Title","My Message","Ok","Cancel");

    QMessageBox::StandardButton result = QMessageBox::question(this,"MY Title","Quit Application ? ",QMessageBox::Yes | QMessageBox::No);

    if(result == QMessageBox::Yes)
    {
        QApplication::quit();
    }else{
        qDebug() << "Click Button No";
    }

}

