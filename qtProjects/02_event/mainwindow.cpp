#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 启动定时器
    id1 = startTimer(1000);       // 参数1：间隔（单位：毫秒）
    id2 = startTimer(2000);
    qDebug() << "id1 = " << id1 << " id2 = " << id2;
}

// 重写定时器事件
void MainWindow::timerEvent(QTimerEvent *e){
    qDebug() << "e->timerId() = " << e->timerId();
    if (e->timerId() == id1){
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    if (e->timerId() == id2){
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

