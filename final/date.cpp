#include "date.h"
#include "ui_date.h"
#include "QDebug"

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

void Date::onDateSelected(const QDate &date)//获得日历信息，并保存在getDate 变量
{
    getDate = date;
    startDate=getDate;

    ui->startEdit->setText(startDate.toString("yyyy-MM-dd"));

    if(!startDate.isNull() && !endDate.isNull()){
        int days = startDate.daysTo(endDate);
        ui->finalEdit->setText(QString::number(days) + "天");
    }
}

void Date::onDateSelected2(const QDate &date)
{
    getDate = date;
    endDate=getDate;

    ui->endEdit->setText(endDate.toString("yyyy-MM-dd"));

    if(!startDate.isNull() && !endDate.isNull()){
        int days = startDate.daysTo(endDate);
        ui->finalEdit->setText(QString::number(days) + "天");
    }
}

void Date::on_btnStart_clicked()//选择开始日期
{
    Calendar *calendarWindow = new Calendar(this);
    calendarWindow->show();

    // 连接Calendar的dateSelected信号到Date的onDateSelected槽函数
    connect(calendarWindow, SIGNAL(dateSelected(QDate)), this, SLOT(onDateSelected(QDate)));


}

void Date::on_btnEnd_clicked()//选择结束日期
{
    Calendar *calendarWindow = new Calendar(this);
    calendarWindow->show();

    // 连接Calendar的dateSelected信号到Date的onDateSelected槽函数
    connect(calendarWindow, SIGNAL(dateSelected(QDate)), this, SLOT(onDateSelected2(QDate)));

}
