#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

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

void MainWindow::on_pushButton_write_clicked()
{
    QFile file("Created File.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","File not open");
    }
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_pushButton_read_clicked()
{
    QString filter = "All File (*.*) ;; Text File (*.txt) ;; XML File (*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"open a file",QDir::homePath(),filter);
    QFile file(file_name);
    // QFile file("Created File.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Error","File not open");
    }
    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());
    file.close();
}


void MainWindow::on_pushButton_clear_clicked()
{
    QFile file("Created File.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::information(this,"Error","File not open");
    }
    file.flush();
    ui->plainTextEdit->clear();
    file.close();
}

