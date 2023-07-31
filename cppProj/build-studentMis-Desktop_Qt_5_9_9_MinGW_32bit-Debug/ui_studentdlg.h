/********************************************************************************
** Form generated from reading UI file 'studentdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDLG_H
#define UI_STUDENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentDlg
{
public:
    QTableView *tableView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushBtnInsert;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushBtnDel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushBtnUpdate;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushBtnFind;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditId;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLineEdit *lineEditScore;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *StudentDlg)
    {
        if (StudentDlg->objectName().isEmpty())
            StudentDlg->setObjectName(QStringLiteral("StudentDlg"));
        StudentDlg->resize(829, 655);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/m12.png"), QSize(), QIcon::Normal, QIcon::Off);
        StudentDlg->setWindowIcon(icon);
        tableView = new QTableView(StudentDlg);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 90, 451, 331));
        groupBox = new QGroupBox(StudentDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 560, 601, 72));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushBtnInsert = new QPushButton(groupBox);
        pushBtnInsert->setObjectName(QStringLiteral("pushBtnInsert"));

        horizontalLayout_3->addWidget(pushBtnInsert);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushBtnDel = new QPushButton(groupBox);
        pushBtnDel->setObjectName(QStringLiteral("pushBtnDel"));

        horizontalLayout_3->addWidget(pushBtnDel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushBtnUpdate = new QPushButton(groupBox);
        pushBtnUpdate->setObjectName(QStringLiteral("pushBtnUpdate"));

        horizontalLayout_3->addWidget(pushBtnUpdate);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushBtnFind = new QPushButton(groupBox);
        pushBtnFind->setObjectName(QStringLiteral("pushBtnFind"));

        horizontalLayout_3->addWidget(pushBtnFind);

        groupBox_2 = new QGroupBox(StudentDlg);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 470, 791, 63));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEditId = new QLineEdit(groupBox_2);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));

        horizontalLayout_2->addWidget(lineEditId);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditName = new QLineEdit(groupBox_2);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout_2->addWidget(lineEditName);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditScore = new QLineEdit(groupBox_2);
        lineEditScore->setObjectName(QStringLiteral("lineEditScore"));

        horizontalLayout_2->addWidget(lineEditScore);

        widget = new QWidget(StudentDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 641, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(false);

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(StudentDlg);

        QMetaObject::connectSlotsByName(StudentDlg);
    } // setupUi

    void retranslateUi(QDialog *StudentDlg)
    {
        StudentDlg->setWindowTitle(QApplication::translate("StudentDlg", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("StudentDlg", "GroupBox", Q_NULLPTR));
        pushBtnInsert->setText(QApplication::translate("StudentDlg", "\346\217\222\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        pushBtnDel->setText(QApplication::translate("StudentDlg", "\345\210\240\351\231\244\346\225\260\346\215\256", Q_NULLPTR));
        pushBtnUpdate->setText(QApplication::translate("StudentDlg", "\346\233\264\346\226\260\346\225\260\346\215\256", Q_NULLPTR));
        pushBtnFind->setText(QApplication::translate("StudentDlg", "\346\237\245\350\257\242\346\225\260\346\215\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("StudentDlg", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("StudentDlg", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("StudentDlg", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("StudentDlg", "\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("StudentDlg", "\346\216\222\345\272\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StudentDlg: public Ui_StudentDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDLG_H
