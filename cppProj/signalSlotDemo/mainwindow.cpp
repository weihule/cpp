#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("信号和槽示例");

    // 创建按钮对象
    QPushButton* btn1 = new QPushButton("关闭窗口", this);
    btn1->move(150, 150);

    // 点击 "关闭窗口" 按钮，关闭窗口
    connect(btn1, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

