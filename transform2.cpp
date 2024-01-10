#include "transform2.h"
#include "ui_transform2.h"

Transform2::Transform2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transform2)
{
    ui->setupUi(this);
}

Transform2::~Transform2()
{
    delete ui;
}
