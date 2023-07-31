#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

class Page2 : public QWidget
{
    Q_OBJECT
public:
    explicit Page2(QWidget *parent = nullptr);

    // 进入主页面
    void toMainPage();

    // 进入最初页面
    void toFirst();

signals:

};

#endif // PAGE2_H
