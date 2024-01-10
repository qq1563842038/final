#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>

namespace Ui {
class Transform;
}

class Transform : public QWidget
{
    Q_OBJECT

public:
    explicit Transform(QWidget *parent = nullptr);
    ~Transform();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
