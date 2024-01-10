#ifndef SCIENCE_H
#define SCIENCE_H

#include <QWidget>

namespace Ui {
class Science;
}

class Science : public QWidget
{
    Q_OBJECT

public:
    explicit Science(QWidget *parent = nullptr);
    ~Science();

signals:
    void goSuccess();
    void goFailed();

private:
    Ui::Science *ui;
};

#endif // SCIENCE_H
