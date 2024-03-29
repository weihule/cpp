#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    // QSpinBox改变，QSlider跟着移动
    void (QSpinBox::* p1)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, p1, ui->horizontalSlider, &QSlider::setValue);

    // QSlider移动，QSpinBox跟着改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

// 设置数字
void SmallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

// 获取数字
int SmallWidget::getNum(){
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
