#ifndef ADDIALOG_H
#define ADDIALOG_H

#include <QDialog>
#include<QDebug>


namespace Ui {
class addialog;
}

class addialog : public QDialog
{
    Q_OBJECT
//
public:
    explicit addialog(QWidget *parent = 0);
    ~addialog();
    //打卡信息
    int pm_month;//打卡日期
    int pm_day;
    int pm_index;//打卡项目编号
    double pm_time;//打卡时长

    void get_data();//获取打卡信息
    void load_data();//将打卡数据写入数据库

//    std::unordered_map<string, int> p_index;

private slots:
    void on_pushButton_clicked();//启动load_data()

private:
    Ui::addialog *ui;


};

#endif // ADDIALOG_H
