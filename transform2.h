#ifndef TRANSFORM2_H
#define TRANSFORM2_H

#include <QWidget>

namespace Ui {
class Transform2;
}

class Transform2 : public QWidget
{
    Q_OBJECT

public:
    explicit Transform2(QWidget *parent = nullptr);
    ~Transform2();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Transform2 *ui;
};

#endif // TRANSFORM2_H
