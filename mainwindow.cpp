#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lineEdit_add(QString s)
{
    ui->lineEdit->setText(ui->lineEdit->text()+s);
}

void MainWindow::on_lineEdit_returnPressed()
{
    Calculate(ui->lineEdit->text());
}

void MainWindow::on_pushButton_12_clicked()
{
    Calculate(ui->lineEdit->text());
}

void MainWindow::on_pushButton_clicked()
{
    this->lineEdit_add("7");
}

void MainWindow::on_pushButton_2_clicked()
{
    this->lineEdit_add("8");
}

void MainWindow::on_pushButton_3_clicked()
{
    this->lineEdit_add("9");
}

void MainWindow::on_pushButton_4_clicked()
{
    this->lineEdit_add("4");
}

void MainWindow::on_pushButton_5_clicked()
{
    this->lineEdit_add("5");
}

void MainWindow::on_pushButton_6_clicked()
{
    this->lineEdit_add("6");
}

void MainWindow::on_pushButton_7_clicked()
{
    this->lineEdit_add("1");
}

void MainWindow::on_pushButton_8_clicked()
{
    this->lineEdit_add("2");
}

void MainWindow::on_pushButton_9_clicked()
{
    this->lineEdit_add("3");
}

void MainWindow::on_pushButton_10_clicked()
{
    this->lineEdit_add("0");
}

void MainWindow::on_pushButton_11_clicked()
{
    this->lineEdit_add(".");
}

void MainWindow::on_pushButton_24_clicked()
{
    this->lineEdit_add("^");
}

void MainWindow::on_pushButton_22_clicked()
{
    this->lineEdit_add("(");
}

void MainWindow::on_pushButton_23_clicked()
{
    this->lineEdit_add(")");
}

void MainWindow::on_pushButton_13_clicked()
{
    this->lineEdit_add("/");
}

void MainWindow::on_pushButton_14_clicked()
{
    this->lineEdit_add("*");
}

void MainWindow::on_pushButton_15_clicked()
{
    this->lineEdit_add("-");
}

void MainWindow::on_pushButton_16_clicked()
{
    this->lineEdit_add("+");
}

void MainWindow::on_pushButton_21_clicked()
{
    this->lineEdit_add("exp(");
}

void MainWindow::on_pushButton_17_clicked()
{
    this->lineEdit_add("sin(");
}

void MainWindow::on_pushButton_18_clicked()
{
    this->lineEdit_add("cos(");
}

void MainWindow::on_pushButton_19_clicked()
{
    this->lineEdit_add("tan(");
}

void MainWindow::on_pushButton_20_clicked()
{
    this->lineEdit_add("ln(");
}

void MainWindow::on_pushButton_26_clicked()
{
    this->lineEdit_add("log(");
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit->setText("");
}
