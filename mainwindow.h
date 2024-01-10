#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
#include "nomal.h"
#include "science.h"
#include "programmer.h"
#include "date.h"
#include "transform.h"
#include "transform2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void goCalculator(QWidget *widget);
    void goNomal();
    void goScience();
    void goProgrammer();
    void goDate();
    void goTransform();
    void goTransform2();


    void on_pushButton_clicked();

    void on_btnScience_clicked();

    void on_btnProgrammer_clicked();

    void on_btnDate_clicked();

    void on_btnTrams1_clicked();

    void on_btnTrans2_clicked();

    void on_btnNomal_clicked();

    void on_btnTrams_clicked();

    void on_btnTrans_clicked();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::MainWindow *ui;

    Nomal *nomal;
    Science *science;
    Programmer *programmer;
    Date *date;
    Transform *transform;
    Transform2 *transform2;
};
#endif // MAINWINDOW_H
