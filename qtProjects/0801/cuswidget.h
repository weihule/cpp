#ifndef CUSWIDGET_H
#define CUSWIDGET_H

#include <QWidget>
#include <QSlider>

namespace Ui {
class CusWidget;
}

class CusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CusWidget(QWidget *parent = nullptr);
    ~CusWidget();

    void setNum(int num);

    int getNum();

private:
    Ui::CusWidget *ui;
};

#endif // CUSWIDGET_H
