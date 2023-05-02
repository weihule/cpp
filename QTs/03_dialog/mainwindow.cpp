#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击菜单栏中的"文件->新建"，弹出模态对话框
    connect(ui->actionnew, &QAction::triggered, [=](){
      QDialog dlg(this);
      dlg.resize(300, 300);
      dlg.exec();
      qDebug() << "模态对话框弹出了";
    });

    // 点击菜单栏中的"文件->打开"，弹出非模态对话框
    connect(ui->actionopen, &QAction::triggered, [=](){
//       // 如果直接这样创建，dlg2是在栈上，当匿名函数执行完之后，对象就释放了
//       // 结果就是窗口一闪而过，而上面是因为dlg.exec()阻塞
//       // QDialog dlg2(this);
//       QDialog *dlg2 = new QDialog(this);
//       dlg2->resize(300, 300);
//       dlg2->show();

//       // 如果一直点击然后关闭这个对话框，会产生很多对象，这些对象只有在整个程序终止时才会
//       // 析构掉，而这样显然不好，所以需要加上下面这个属性，这样关闭这个对话框的时候，
//       // 该对象也就随之释放掉了
//       dlg2->setAttribute(Qt::WA_DeleteOnClose);

//       qDebug() << "非模态对话框弹出了";

        // 提问对话框
//        if (QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)){
//            qDebug() << "点击的是保存";
//        }
//        else{
//            qDebug() << "点击的是取消";
//        }
        // QMessageBox::warning(this, "warn", "警告");

        QColor color = QColorDialog::getColor(QColor(Qt::red));
        qDebug() << color.red() << color.green() << color.blue();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

