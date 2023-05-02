#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ui->actionnew->setIcon(QIcon("D:/Desktop/R-C.png"));

    // 使用QT资源文件: ": 前缀名 文件名"
    ui->actionnew->setIcon(QIcon(":/icons/R-C2.png"));
    ui->actionopen->setIcon(QIcon(":/icons/R-C.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

