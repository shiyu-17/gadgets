#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();
    void get_mdata();//获取基本信息
    void load_data();//用户信息载入数据库

private:
    Ui::myDialog *ui;
    //个人信息
    QString name;
    QString sex;
    QString age;
    QString height;
    double weight;


signals://自定义信号
    void mysigValue(double w,QString h);

private slots:
    void on_pushButton_clicked();

};

#endif // MYDIALOG_H
