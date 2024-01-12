#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    goNomal();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goCalculator(QWidget *widget)//进入计算器辅助函数
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->labelTitel->setText(widget->windowTitle());
}

void MainWindow::goNomal()//跳转函数
{
    qDebug()<<"goNomal";
    nomal =new Nomal();
    goCalculator(nomal);
}

void MainWindow::goScience()
{
    qDebug()<<"goScience";
    science =new Science();
    goCalculator(science);
}

void MainWindow::goProgrammer()
{
    qDebug()<<"goProgrammer";
    programmer =new Programmer();
    goCalculator(programmer);
}

void MainWindow::goDate()
{
    qDebug()<<"goDate";
    date =new Date();
    goCalculator(date);
}

void MainWindow::goTransform()
{
    qDebug()<<"goTransform";
    transform =new Transform();
    goCalculator(transform);
}

void MainWindow::goTransform2()
{
    qDebug()<<"goTransform2";
    transform2 =new Transform2();
    goCalculator(transform2);
}

void MainWindow::on_btnNomal_clicked()
{
    goNomal();
}

void MainWindow::on_btnScience_clicked()
{
    goScience();
}

void MainWindow::on_btnProgrammer_clicked()
{
    goProgrammer();
}

void MainWindow::on_btnDate_clicked()
{
    goDate();
}

void MainWindow::on_btnTrans_clicked()
{
    goTransform();
}

void MainWindow::on_btnTrans2_clicked()
{
    goTransform2();
}







