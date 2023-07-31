#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QPushButton>

class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(QWidget *parent = nullptr);

    // 槽函数
    void mainPageSlot();

signals:
    void mainPageSignal();
};

#endif // MAINPAGE_H
