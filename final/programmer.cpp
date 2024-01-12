#include "programmer.h"
#include "ui_programmer.h"
#include "QDebug"
#include "math.h"

Programmer::Programmer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Programmer)
{
    ui->setupUi(this);
    ui->radioButton_3->click();

    digitBTNs={
        {Qt::Key_0,ui->btnNum0},
        {Qt::Key_1,ui->btnNum1},
        {Qt::Key_2,ui->btnNum2},
        {Qt::Key_3,ui->btnNum3},
        {Qt::Key_4,ui->btnNum4},
        {Qt::Key_5,ui->btnNum5},
        {Qt::Key_6,ui->btnNum6},
        {Qt::Key_7,ui->btnNum7},
        {Qt::Key_8,ui->btnNum8},
        {Qt::Key_9,ui->btnNum9},

        {Qt::Key_A,ui->btnNumA},
        {Qt::Key_B,ui->btnNumB},
        {Qt::Key_C,ui->btnNumC},
        {Qt::Key_D,ui->btnNumD},
        {Qt::Key_E,ui->btnNumE},
        {Qt::Key_F,ui->btnNumF},
    };
    operatorBTNs={
        {Qt::Key_Asterisk,ui->btnMultiple},
        {Qt::Key_Slash,ui->btnDivide},
        {Qt::Key_Plus,ui->btnAdd},
        {Qt::Key_Minus,ui->btnSubtract},
    };
    /*绑定按钮*/
    foreach(auto btn,digitBTNs){
        connect(btn, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
    }
//    connect(ui->btnNum0, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum1, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum2, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum3, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum4, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum5, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum6, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum7, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum8, SIGNAL(clicked()), this, SLOT(btnNumClicked()));
//    connect(ui->btnNum9, SIGNAL(clicked()), this, SLOT(btnNumClicked()));

    //加减乘除
    foreach(auto btn,operatorBTNs){
        connect(btn, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    }
    /*connect(ui->btnMultiple, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnSubtract, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));*/


    //单操作数符号
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
}

Programmer::~Programmer()
{
    delete ui;
}


QString Programmer::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2 && opcodes.size()>0){
        //取操作数和操作符号
        double operand1, operand2;
        QString op=opcodes.front();
        opcodes.pop_front();

        bool ok1, ok2;
        operand1=operands.front().toInt(&ok1, base2);  // 从指定进制转换为十进制
        operands.pop_front();
        operand2=operands.front().toInt(&ok2, base2);  // 从指定进制转换为十进制
        operands.pop_front();

        if(ok1 && ok2) {
            if(op=="+"){
                result=operand1+operand2;
            }
            else if(op=="-"){
                result=operand1-operand2;
            }
            else if(op=="×"){
                result=operand1*operand2;
            }
            else if(op=="/"){
                result=operand1/operand2;
            }
            operands.push_back(QString::number((int)result, base2));  // 将结果转换为指定进制
        }
    }

    return QString::number((int)result, base2);  // 将结果转换为指定进制
}




void Programmer::btnNumClicked()
{
    /*从键盘输出按键*/
    QString digit = qobject_cast<QPushButton*>(sender())->text();
    if(digit=="0" && operand=="0")
        digit="";
    if(digit!="0" && operand=="0")
        operand="";
    operand+=digit;
    ui->display->setText(operand);

}

void Programmer::btnBinaryOperatorClicked()
{
    opcode=qobject_cast<QPushButton *>(sender())->text();
    if(operand !=""){
        operands.push_back(operand);
        operand="";

        opcodes.push_back(opcode);
        QString result=calculation();
        ui->display->setText(result);
    }
}

void Programmer::btnUnaryOperatorClicked()
{
    if(operand !=""){
        double result=operand.toDouble();
        operand="";

        QString op=qobject_cast<QPushButton *>(sender())->text();

        int i,size1=operands.size(),size2=opcodes.size();
        for(i=0;i<size1;i++)
            operands.pop_front();
        for(i=0;i<size2;i++)
            opcodes.pop_front();
        if(op=="±"){
            result=0-result;
        }
        operand=QString :: number(result);
        ui->display->setText(QString :: number(result));
    }
}

void Programmer::on_btnPoint_clicked()//“.”
{
    if(!operand.contains(".")){
        operand+=qobject_cast<QPushButton*>(sender())->text();
    }
    ui->display->setText(operand);
}

void Programmer::on_btnDelete_clicked()//“⌫”
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}

void Programmer::on_btnC_clicked()//“C”
{
    int i,size1=operands.size(),size2=opcodes.size();
    operand.clear();
    ui->display->setText(operand);
    for(i=0;i<size1;i++)
        operands.pop_front();
    for(i=0;i<size2;i++)
        opcodes.pop_front();
}

void Programmer::on_btnEqual_clicked()//“=”
{
    QString result;
    if(opcodes.size()!=0){
        if(operand !=""){
            operands.push_back(operand);
            operand="";
        }
        result=calculation();
        operand=result;

        int i,size1=operands.size(),size2=opcodes.size();
        for(i=0;i<size1;i++)
            operands.pop_front();
        for(i=0;i<size2;i++)
            opcodes.pop_front();
    }
    ui->display->setText(operand);
}

void Programmer::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey,digitBTNs.keys()){
        if(event->key()==btnKey)
            digitBTNs[btnKey]->animateClick(100);
    }
    foreach(auto btnKey,operatorBTNs.keys()){
        if(event->key()==btnKey)
            operatorBTNs[btnKey]->animateClick(100);
    }

    if (event->key() == Qt::Key_Equal || event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) // "=" 键
    {
        ui->btnEqual->animateClick(100); // 模拟按钮点击
    }

    if (event->key() == Qt::Key_Period) // "." 键
    {
        ui->btnPoint->animateClick(100); // 模拟按钮点击
    }
    if (event->key() == Qt::Key_Backspace) // "Backspace" 键
    {
        ui->btnDelete->animateClick(100); // 模拟按钮点击
    }

}

void Programmer::on_btnCE_clicked()//ce键
{
    operand.clear();
    ui->display->setText(operand);
}

void Programmer::on_radioButton_1_clicked()//2进制
{
    base1=base2;
    base2=2;//2进制
    clearOperandsAndConvertOperand();
    // 禁用btnNum2到btnNumF
    ui->btnNum2->setEnabled(false);
    ui->btnNum3->setEnabled(false);
    ui->btnNum4->setEnabled(false);
    ui->btnNum5->setEnabled(false);
    ui->btnNum6->setEnabled(false);
    ui->btnNum7->setEnabled(false);
    ui->btnNum8->setEnabled(false);
    ui->btnNum9->setEnabled(false);
    ui->btnNumA->setEnabled(false);
    ui->btnNumB->setEnabled(false);
    ui->btnNumC->setEnabled(false);
    ui->btnNumD->setEnabled(false);
    ui->btnNumE->setEnabled(false);
    ui->btnNumF->setEnabled(false);
}

void Programmer::on_radioButton_2_clicked()//8进制
{
    base1=base2;
    base2=8;//8进制
    clearOperandsAndConvertOperand();
    // 禁用btnNum8到btnNumF
    ui->btnNum2->setEnabled(true);
    ui->btnNum3->setEnabled(true);
    ui->btnNum4->setEnabled(true);
    ui->btnNum5->setEnabled(true);
    ui->btnNum6->setEnabled(true);
    ui->btnNum7->setEnabled(true);
    ui->btnNum8->setEnabled(false);
    ui->btnNum9->setEnabled(false);
    ui->btnNumA->setEnabled(false);
    ui->btnNumB->setEnabled(false);
    ui->btnNumC->setEnabled(false);
    ui->btnNumD->setEnabled(false);
    ui->btnNumE->setEnabled(false);
    ui->btnNumF->setEnabled(false);
}

void Programmer::on_radioButton_3_clicked()//10进制
{
    base1=base2;
    base2=10;//10进制
    clearOperandsAndConvertOperand();
    // 禁用btnNumA到btnNumF
    ui->btnNum2->setEnabled(true);
    ui->btnNum3->setEnabled(true);
    ui->btnNum4->setEnabled(true);
    ui->btnNum5->setEnabled(true);
    ui->btnNum6->setEnabled(true);
    ui->btnNum7->setEnabled(true);
    ui->btnNum8->setEnabled(true);
    ui->btnNum9->setEnabled(true);
    ui->btnNumA->setEnabled(false);
    ui->btnNumB->setEnabled(false);
    ui->btnNumC->setEnabled(false);
    ui->btnNumD->setEnabled(false);
    ui->btnNumE->setEnabled(false);
    ui->btnNumF->setEnabled(false);
}

void Programmer::on_radioButton_4_clicked()//16进制
{
    base1=base2;
    base2=16;//16进制
    clearOperandsAndConvertOperand();
    // 不禁用btnNum
    ui->btnNum2->setEnabled(true);
    ui->btnNum3->setEnabled(true);
    ui->btnNum4->setEnabled(true);
    ui->btnNum5->setEnabled(true);
    ui->btnNum6->setEnabled(true);
    ui->btnNum7->setEnabled(true);
    ui->btnNum8->setEnabled(true);
    ui->btnNum9->setEnabled(true);
    ui->btnNumA->setEnabled(true);
    ui->btnNumB->setEnabled(true);
    ui->btnNumC->setEnabled(true);
    ui->btnNumD->setEnabled(true);
    ui->btnNumE->setEnabled(true);
    ui->btnNumF->setEnabled(true);
}

void Programmer::clearOperandsAndConvertOperand()
{
    operands.clear();

    // 如果operand不为空，将其转换为base2对应基数的字符串并更新显示
    if (!operand.isEmpty()) {
        int value = operand.toInt(nullptr, base1); // 先将operand转换为base1进制的整数
        operand = QString::number(value, base2); // 将整数转换为base2对应基数的字符串
        ui->display->setText(operand);
    }
}
