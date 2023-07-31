#ifndef STUDENTDLG_H
#define STUDENTDLG_H

#include <QDialog>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentDlg; }
QT_END_NAMESPACE

class StudentDlg : public QDialog
{
    Q_OBJECT

public:
    StudentDlg(QWidget *parent = nullptr);
    ~StudentDlg();

    void slotIndexChanged(const QString &str);

private:
    Ui::StudentDlg *ui;
};
#endif // STUDENTDLG_H
