#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

// 鼠标进入事件
void MyLabel::enterEvent(QEvent *event){
    qDebug() << "鼠标进入了";
}

// 鼠标离开事件
void MyLabel::leaveEvent(QEvent *event){
    qDebug() << "鼠标离开了";
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    qDebug() << "鼠标移动了";
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    QString str = QString("鼠标按下了 x=%1, y=%2, gx=%3, gy=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
    qDebug() << "鼠标按下了";
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    QString str = QString("鼠标按下了 x=%1, y=%2, gx=%3, gy=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
    qDebug() << "鼠标松开了";
}

bool event(QEvent *e){
    // 如果鼠标按下，在event中做事件拦截
    if (e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event函数中，鼠标按下了 x=%1, y=%2, gx=%3, gy=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;

        return true;    // true表示用户自己处理这个事件，不向下分发了
    }

    // 其他事件，交给父类处理
    return QLabel::event(e);
}
