#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "testmillerrabin.h"
#include "basecommands.h"
#include "gmpxx.h"

baseCommands base;
AlgorithmMillerRabin alg{55};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->keysTxtField->setText(QString("Нынешние ключи для безопасности: \n") + QString::fromStdString(alg.getStrKeys()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    FileInput file{"PrimeNumbers.txt"};
    file.restart();
    int howNumbers = base.getLustNumberFromText(ui->lineEditHowNumbers->text());
    alg.computeNumersPrime(howNumbers);

    base.inputTextToFile(base.viewArrayInText(alg.getHVec()), file);
}


void MainWindow::on_pushButton_2_clicked()
{
    alg.setKeys(ui->keysInputField->text().toStdString());
    ui->keysTxtField->setText(QString("Нынешние ключи для безопасности: \n") + QString::fromStdString(alg.getStrKeys()));
}

