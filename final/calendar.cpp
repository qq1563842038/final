#include "calendar.h"
#include "ui_calendar.h"
#include "QDebug"

Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    getDate = date;
    qDebug()<<getDate;
}

void Calendar::on_buttonBox_accepted()
{
    emit dateSelected(getDate);
}
