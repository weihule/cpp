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
    QString str = QString("鼠标按下了(相对控件)  x = %1  y = %2 global_x = %3 global_y = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    qDebug() << "鼠标释放了";
}
