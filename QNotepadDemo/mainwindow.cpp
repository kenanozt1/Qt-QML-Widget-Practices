#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QPrinter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , flushFile(1)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    this->setWindowIcon(QIcon(":/img/notepad.png"));
    this->setWindowTitle("Notepad");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    if(filePath != "" or ui->textEdit->toPlainText() != ""){
        QMessageBox::StandardButton result = QMessageBox::question(this,"Save","Save To File",QMessageBox::Yes | QMessageBox::No);
        if(result == QMessageBox::Yes){
            if(filePath == "")
                on_actionSave_as_triggered();
            else
                on_actionSave_triggered();
        }else{
         return;
        }
    }
    if(flushFile == 1){
        ui->textEdit->clear();
        filePath = "";
        this->setWindowTitle("Notepad");
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QString filter = "All File (*.*) ;; Text File (*.txt) ;; XML Fİle (*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open a File",nullptr,filter);
    this->setWindowTitle(file_name);
    QFile file(file_name);
    filePath = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Error","File not open");
        flushFile = 0;
        return;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    // QString file_name = QFileDialog::getOpenFileName(this,"Open a File");
    QFile file(filePath);
    // filePath = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Error","File not open");
        flushFile = 0;
        return;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString filter = "All File (*.*) ;; Text File (*.txt) ;; XML Fİle (*.xml)";
    QString file_name = QFileDialog::getSaveFileName(this,"Open a File",nullptr,filter);
    QFile file(file_name);
    this->setWindowTitle(file_name);
    filePath = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Error","File not open");
        flushFile = 0;
        return;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString aboutText;
    aboutText = "Author : Somebody\n";
    aboutText += "Date : 06/02/2025";
    QMessageBox::about(this,"About Notepad",aboutText);
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok){
        ui->textEdit->setFont(font);
    }else return;

}


void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }else return;
}


void MainWindow::on_actionText_Background_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }else return;
}


void MainWindow::on_actionPalette_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this);
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }else return;
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}

