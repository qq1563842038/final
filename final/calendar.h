#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include <QDate>


namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

    QDate getDate;

signals:
    void dateSelected(const QDate &date);

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_buttonBox_accepted();

private:
    Ui::Calendar *ui;
};

#endif // CALENDAR_H
