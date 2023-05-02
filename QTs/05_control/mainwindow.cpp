#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 单行添加
    QListWidgetItem* item = new QListWidgetItem("锄禾日当午");
    // 水平居中
    item->setTextAlignment(Qt::AlignHCenter);
    ui->listWidget->addItem(item);

    // 多行添加
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

