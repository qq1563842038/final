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

private slots:
    void on_display1_textEdited(const QString &arg1);

    void on_display2_textEdited(const QString &arg1);

    void on_comboBox1_currentIndexChanged(int index);

    void on_comboBox2_currentIndexChanged(int index);

    void on_btnClear_clicked();

    void on_btnClear2_clicked();

private:
    Ui::Transform *ui;

    double multiplier1;//汇率1
    double multiplier2;//汇率2
    double number;
    int status=1;//当前选择输入框
};

#endif // TRANSFORM_H
