#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    // 鼠标进入事件
    void enterEvent(QEvent *event);

    // 鼠标离开事件
    void leaveEvent(QEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);

    // 通过event事件分发器来拦截鼠标按下事件
    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
