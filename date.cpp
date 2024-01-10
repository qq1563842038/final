#include "date.h"
#include "ui_date.h"

Date::Date(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Date)
{
    ui->setupUi(this);
}

Date::~Date()
{
    delete ui;
}
