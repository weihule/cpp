#include "mainpage.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent)
{
    QPushButton* btn1 = new QPushButton("Back First", this);
    btn1->move(50, 50);
    resize(480, 480);

    connect(btn1, &QPushButton::clicked, this, &MainPage::main_page_slot);
}

void MainPage::main_page_slot(){
    emit main_page_signal();    // 触发信号
}
