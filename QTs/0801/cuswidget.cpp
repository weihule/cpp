#include "cuswidget.h"
#include "ui_cuswidget.h"

CusWidget::CusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusWidget)
{
    ui->setupUi(this);

    void (QSpinBox::* p1)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, p1, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void CusWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

int CusWidget::getNum(){
    return ui->spinBox->value();
}

CusWidget::~CusWidget()
{
    delete ui;
}
