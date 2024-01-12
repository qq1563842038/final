#include "transform.h"
#include "ui_transform.h"

Transform::Transform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transform)
{
    ui->setupUi(this);

    multiplier1=1.0;
    multiplier2=1.0;
    ui->display1->setValidator(new QDoubleValidator(this));
    ui->display2->setValidator(new QDoubleValidator(this));
}

Transform::~Transform()
{
    delete ui;
}

void Transform::on_display1_textEdited(const QString &arg1)
{
    status=1;
    number = arg1.toDouble();
    ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
}

void Transform::on_display2_textEdited(const QString &arg1)
{
    status=2;
    number = arg1.toDouble();
    ui->display1->setText(QString::number(number * multiplier2 /multiplier1));
}

void Transform::on_comboBox1_currentIndexChanged(int index)
{
    if(index==0)
        multiplier1=1;
    else if(index==1)
        multiplier1=7.17;
    else if(index==2)
        multiplier1=7.85;
    else if(index==3)
        multiplier1=9.13;
    else if(index==4)
        multiplier1=0.05;

    if(status==1)
        ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
    else if(status==2)
        ui->display1->setText(QString::number(number * multiplier2 /multiplier1));

}

void Transform::on_comboBox2_currentIndexChanged(int index)
{
    if(index==0)
        multiplier2=1;
    else if(index==1)
        multiplier2=7.17;
    else if(index==2)
        multiplier2=7.85;
    else if(index==3)
        multiplier2=9.13;
    else if(index==4)
        multiplier2=0.05;

    if(status==1)
        ui->display2->setText(QString::number(number * multiplier1 /multiplier2));
    else if(status==2)
        ui->display1->setText(QString::number(number * multiplier2 /multiplier1));


}

void Transform::on_btnClear_clicked()
{
    ui->display1->clear();
    ui->display2->clear();
}

void Transform::on_btnClear2_clicked()
{
    ui->display1->clear();
    ui->display2->clear();
}
