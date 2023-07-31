#include "mainpage.h"

MainPage::MainPage(QWidget *parent) : QWidget(parent)
{
   QPushButton* btn1 = new QPushButton("Back First", this);
   btn1->move(50, 50);

   connect(btn1, &QPushButton::clicked, this, &MainPage::mainPageSlot);
}

void MainPage::mainPageSlot()
{
    emit mainPageSignal();
}
