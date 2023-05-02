#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置列数
    ui->tableWidget->setColumnCount(3);

    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    // 设置行数
    ui->tableWidget->setRowCount(5);

    // 设置正文
    QStringList nameList;
    nameList << "关羽" << "诸葛亮" << "勾践" << "曹操" << "花木兰";

    QStringList sexList;
    sexList << "男" << "男" << "男" << "男" << "女";

    ui->tableWidget->setItem(0, 0, new  QTableWidgetItem("亚瑟"));
    for (int i=0; i < 5; i++){
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        // int转QString
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i+18)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

