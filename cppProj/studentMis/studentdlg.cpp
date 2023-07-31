#include "studentdlg.h"
#include "ui_studentdlg.h"

StudentDlg::StudentDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentDlg)
{
    ui->setupUi(this);

    ui->comboBox_2->addItem("苹果");
    ui->comboBox_2->addItem("香蕉");
    ui->comboBox_2->addItems({ "葡萄","哈密瓜"});
    ui->comboBox_2->insertItem(1, "桃子");

    ui->comboBox_2->setCurrentIndex(1);

    qDebug() << ui->comboBox_2->currentIndex();

    connect(ui->comboBox_2, &QComboBox::currentTextChanged, [=](const QString &str){
        qDebug() << str;
        qDebug() << ui->comboBox_2->currentIndex();
    });

}

StudentDlg::~StudentDlg()
{
    delete ui;
}

