#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号，返回值为void，只声明不实现，可以有参数（可以重载）
    void hungry();

    void hungry(QString food_name);

};

#endif // TEACHER_H
