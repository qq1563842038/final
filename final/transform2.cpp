#include "transform2.h"
#include "ui_transform2.h"

Transform2::Transform2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transform2)
{
    ui->setupUi(this);

    multiplier1=1.0;
    multiplier2=1.0;
    ui->display1->setValidator(new QDoubleValidator(this));
    ui->display2->setValidator(new QDoubleValidator(this));
}

Transform2::~Transform2()
{
    delete ui;
}

void Transform2::on_display1_textEdited(const QString &arg1)
{
    status=1;
    number = arg1.toDouble();
    ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
}

void Transform2::on_display2_textEdited(const QString &arg1)
{
    status=2;
    number = arg1.toDouble();
    ui->display1->setText(QString::number(number * multiplier2 /multiplier1));
}

void Transform2::on_comboBox1_currentIndexChanged(int index)
{
    if(index==0)
        multiplier1=1;
    else if(index==1)
        multiplier1=1000;
    else if(index==2)
        multiplier1=1;
    else if(index==3)
        multiplier1=1000;
    else if(index==4)
        multiplier1=1000000;
    else if(index==5)
        multiplier1=4.928922;
    else if(index==6)
        multiplier1=14.78676;
    else if(index==7)
        multiplier1=29.57353;
    else if(index==8)
        multiplier1=236.5882;
    else if(index==9)
        multiplier1=473.1765;
    else if(index==10)
        multiplier1=946.3529;
    else if(index==11)
        multiplier1=3785.412;

    if(status==1)
        ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
    else if(status==2)
        ui->display1->setText(QString::number(number * multiplier2 /multiplier1));

}

void Transform2::on_comboBox2_currentIndexChanged(int index)
{
    if(index==0)
        multiplier2=1;
    else if(index==1)
        multiplier2=1000;
    else if(index==2)
        multiplier2=1;
    else if(index==3)
        multiplier2=1000;
    else if(index==4)
        multiplier2=1000000;
    else if(index==5)
        multiplier2=4.928922;
    else if(index==6)
        multiplier2=14.78676;
    else if(index==7)
        multiplier2=29.57353;
    else if(index==8)
        multiplier2=236.5882;
    else if(index==9)
        multiplier2=473.1765;
    else if(index==10)
        multiplier2=946.3529;
    else if(index==11)
        multiplier2=3785.412;

    if(status==1)
        ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
    else if(status==2)
        ui->display1->setText(QString::number(number * multiplier2 /multiplier1));


}

void Transform2::on_btnClear_clicked()
{
    ui->display1->clear();
    ui->display2->clear();
}

void Transform2::on_btnClear2_clicked()
{
    ui->display1->clear();
    ui->display2->clear();
}
