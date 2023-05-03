#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击移动按钮，移动图片
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        // 如果要手动调用绘图事件，用update更新
        update();
    });
}

// 绘图事件
void MainWindow::paintEvent(QPaintEvent *){
    // 这里的this不是指绑定到对象树，是在当前设备上绘图
    QPainter painter(this);

    // 设置画笔
    QPen pen(QColor(255, 0, 0));

    // 使用这个画笔
    painter.setPen(pen);

    // 画线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    // 画圆(椭圆) (const QPoint &center, int rx, int ry)
    painter.drawEllipse(QPoint(100, 100), 80, 50);

    // 画矩形 (int x, int y, int w, int h)
    painter.drawRect(100, 100, 70, 40);

    // 写文字
    painter.drawText(150, 150, "中国Boys");

    // 画资源图片
    pos_x += 2;
    pos_y += 2;
    painter.drawPixmap(pos_x, pos_y, QPixmap(":/Images/African-hunting-dog_0002.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

