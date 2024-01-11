#ifndef SCIENCE_H
#define SCIENCE_H

#include <QWidget>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>

namespace Ui {
class Science;
}

class Science : public QWidget
{
    Q_OBJECT

public:
    explicit Science(QWidget *parent = nullptr);
    ~Science();

    QString operand;//当前输入框的操作数
    QString opcode;//当前输入框的操作符号
    QStack<QString> operands;//运算堆栈
    QStack<QString> opcodes;//运算符号堆栈
    QMap<int,QPushButton*>digitBTNs;//存放按钮指针
    QMap<int,QPushButton*>operatorBTNs;//存放按钮指针
    QString calculation(bool *ok=NULL);//计算函数


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

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Science *ui;
};

#endif // SCIENCE_H
