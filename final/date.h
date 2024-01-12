#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include <calendar.h>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
#include <QDate>

namespace Ui {
class Date;
}

class Date : public QWidget
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

    QDate getDate;
    QDate startDate;
    QDate endDate;

public slots:
    void onDateSelected(const QDate &date);
    void onDateSelected2(const QDate &date);

signals:
    void goSuccess();
    void goFailed();

private slots:
    void on_btnStart_clicked();

    void on_btnEnd_clicked();

private:
    Ui::Date *ui;
};

#endif // DATE_H
