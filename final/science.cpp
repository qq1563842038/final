#include "science.h"
#include "ui_science.h"
#include "QDebug"
#include "math.h"
#include <QtMath>

Science::Science(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Science)
{
    ui->setupUi(this);

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
        {Qt::Key_E,ui->btnNumE},
        {Qt::Key_P,ui->btnNumPi},
    };
    operatorBTNs={
        {Qt::Key_Asterisk,ui->btnMultiple},
        {Qt::Key_Slash,ui->btnDivide},
        {Qt::Key_Plus,ui->btnAdd},
        {Qt::Key_Minus,ui->btnSubtract},
        {Qt::Key_AsciiCircum,ui->btnPower},
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
    connect(ui->btnPercentage, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));

    connect(ui->btnLog, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnLn, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSin, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnCos, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnTan, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
}

Science::~Science()
{
    delete ui;
}

QString Science::calculation(bool *ok)//双数操作符
{
    double result=0;
    if(operands.size()==2 && opcodes.size()>0){
        //取操作数和操作符号
        double operand1=operands.front().toDouble();
        operands.pop_front();
        double operand2=operands.front().toDouble();
        operands.pop_front();
        QString op=opcodes.front();
        opcodes.pop_front();

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
        else if(op=="x^y"){
            result=qPow(operand1, operand2);
        }
        operands.push_back(QString :: number(result));
    }


    return QString::number(result);
}

void Science::btnNumClicked()
{
    /*从键盘输出按键*/
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    // 清空输入框的逻辑
    if (digit == "e") {
        operand = QString::number(std::exp(1.0));  // e的值
    } else if (digit == "π") {
        operand = QString::number(M_PI);  // π的值
    } else {
        if (digit == "0" && operand == "0")
            digit = "";
        if (digit != "0" && operand == "0")
            operand = "";
        operand += digit;
    }

    ui->display->setText(operand);

}

void Science::btnBinaryOperatorClicked()
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

void Science::btnUnaryOperatorClicked()//单操作符
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
        if(op=="%"){
            result /=100.0;
        }
        else if(op=="1/x"){
            result=1/result;
        }
        else if(op=="x^2"){
            result *=result;
        }
        else if(op=="√"){
            result=sqrt(result);
        }
        else if(op=="±"){
            result=0-result;
        }

        else if(op=="log"){
            result = qLn(result) / qLn(10.0);  // 计算以10为底的对数
        }
        else if(op=="ln"){
            result = qLn(result);  // 计算自然对数
        }
        else if(op=="sin"){
            result = qSin(qDegreesToRadians(result));  // 计算正弦值，operand1 应该是弧度
        }
        else if(op=="cos"){
            result = qCos(qDegreesToRadians(result));  // 计算余弦值，operand1 应该是弧度
        }
        else if(op=="tan"){
            result = qTan(qDegreesToRadians(result));  // 计算正切值，operand1 应该是弧度
        }
        operand=QString :: number(result);
        ui->display->setText(QString :: number(result));
    }
}

void Science::on_btnPoint_clicked()//“.”
{
    if(!operand.contains(".")){
        operand+=qobject_cast<QPushButton*>(sender())->text();
    }
    ui->display->setText(operand);
}

void Science::on_btnDelete_clicked()//“⌫”
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}

void Science::on_btnC_clicked()//“C”
{
    int i,size1=operands.size(),size2=opcodes.size();
    operand.clear();
    ui->display->setText(operand);
    for(i=0;i<size1;i++)
        operands.pop_front();
    for(i=0;i<size2;i++)
        opcodes.pop_front();
}

void Science::on_btnEqual_clicked()//“=”
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

void Science::keyPressEvent(QKeyEvent *event)//模拟点击
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
    if (event->key() == Qt::Key_Percent) // "%" 键
    {
        ui->btnPercentage->animateClick(100); // 模拟按钮点击
    }

    if (event->key() == Qt::Key_G) // "log" 键
    {
        ui->btnLog->animateClick(100); // 模拟按钮点击
    }
    if (event->key() == Qt::Key_N) // "ln" 键
    {
        ui->btnLn->animateClick(100); // 模拟按钮点击
    }
    if (event->key() == Qt::Key_S) // "sin" 键
    {
        ui->btnSin->animateClick(100); // 模拟按钮点击
    }
    if (event->key() == Qt::Key_C) // "cos" 键
    {
        ui->btnCos->animateClick(100); // 模拟按钮点击
    }
    if (event->key() == Qt::Key_T) // "tan" 键
    {
        ui->btnTan->animateClick(100); // 模拟按钮点击
    }
}

void Science::on_btnCE_clicked()//ce键
{
    operand.clear();
    ui->display->setText(operand);
}
