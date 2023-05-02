#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QPushButton>

class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(QWidget *parent = nullptr);

    // 编写槽函数
    void main_page_slot();

signals:
    void main_page_signal();
};

#endif // MAINPAGE_H
