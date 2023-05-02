#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 使用Qt资源：": 前缀名 文件名"
    ui->actionnew->setIcon(QIcon(":/Icons/R-C.png"));
    ui->actionopen->setIcon(QIcon(":/Icons/R-C2.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

