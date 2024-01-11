#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QWidget>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>

namespace Ui {
class Programmer;
}

class Programmer : public QWidget
{
    Q_OBJECT

public:
    explicit Programmer(QWidget *parent = nullptr);
    ~Programmer();

    QString operand;//当前输入框的操作数
    QString opcode;//当前输入框的操作符号
    QStack<QString> operands;//运算堆栈
    QStack<QString> opcodes;//运算符号堆栈
    QMap<int,QPushButton*>digitBTNs;//存放按钮指针
    QMap<int,QPushButton*>operatorBTNs;//存放按钮指针
    QString calculation(bool *ok=NULL);//计算函数

    int base1;//前一次的进制变量
    int base2;//当前的进制变量


private slots:
    void btnNumClicked();//数字按键槽函数
    void btnBinaryOperatorClicked();//加减乘除按键槽函数
    void btnUnaryOperatorClicked();//单操作数按键槽函数
    void on_btnPoint_clicked();

    void on_btnDelete_clicked();

    void on_btnC_clicked();

    void on_btnEqual_clicked();

    virtual void keyPressEvent(QKeyEvent *event);

    void on_btnCE_clicked();

    void on_radioButton_1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void clearOperandsAndConvertOperand();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Programmer *ui;
};

#endif // PROGRAMMER_H
