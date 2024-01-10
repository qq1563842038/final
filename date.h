#ifndef DATE_H
#define DATE_H

#include <QWidget>

namespace Ui {
class Date;
}

class Date : public QWidget
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Date *ui;
};

#endif // DATE_H
