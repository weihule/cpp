#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍" << "金额");

    // 设置并加载顶层节点
    QTreeWidgetItem* item1 = new QTreeWidgetItem(QStringList()<< "力量");
    QTreeWidgetItem* item2 = new QTreeWidgetItem(QStringList()<< "敏捷");
    QTreeWidgetItem* item3 = new QTreeWidgetItem(QStringList()<< "智力");
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    // 追加子节点
    QStringList hero1;
    hero1 << "刚背猪" << "前排坦克，能在吸收伤害的同事造成可观的输出";
    QTreeWidgetItem* l1 = new QTreeWidgetItem(hero1);
    item1->addChild(l1);

    QStringList hero2;
    hero2 << "船长" << "前排坦克，能肉能输出能控场的全局英雄" << "￥120";
    QTreeWidgetItem* l2 = new QTreeWidgetItem(hero2);
    item1->addChild(l2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

