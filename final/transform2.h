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

private slots:
    void on_display1_textEdited(const QString &arg1);

    void on_display2_textEdited(const QString &arg1);

    void on_comboBox1_currentIndexChanged(int index);

    void on_comboBox2_currentIndexChanged(int index);

    void on_btnClear_clicked();

    void on_btnClear2_clicked();

private:
    Ui::Transform2 *ui;

    double multiplier1;//汇率1
    double multiplier2;//汇率2
    double number;
    int status=1;//当前选择输入框
};

#endif // TRANSFORM2_H
