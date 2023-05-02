#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击获取，获取控件当前的值
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getNum();
    });

    // 设置到一半
    connect(ui->btn_set_half, &QPushButton::clicked, [=](){
        ui->widget->setNum(50);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

