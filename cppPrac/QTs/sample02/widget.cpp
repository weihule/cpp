#include "widget.h"
#include "ui_widget.h"
#include "mainpage.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化
    mp = new MainPage;

    QPushButton* btn1 = new QPushButton("Login", this);
    btn1->move(50, 50);

    connect(btn1, &QPushButton::clicked, this, &Widget::to_main_page);

    connect(mp, &MainPage::main_page_signal, this, &Widget::to_first);
}

// 进入主页面
void Widget::to_main_page(){
    mp->show();
    this->hide();
}

// 进入最初的页面
void Widget::to_first(){
    mp->hide();
    this->show();
}

Widget::~Widget()
{
    delete ui;
}

