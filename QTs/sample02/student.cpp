#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug() << "eat with teacher";
}

void Student::treat(QString food_name){
    // 如果是QString类型，输出会有引号
    // QString -> char *, 先转QByteArray，再转char *
    qDebug() << "eat with teacher, food is " << food_name.toUtf8().data();
}
