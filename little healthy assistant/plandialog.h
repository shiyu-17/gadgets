#ifndef PLANDIALOG_H
#define PLANDIALOG_H

#include <QDialog>
#include <QTimeEdit>
#include <QTimer>


namespace Ui {
class planDialog;
}



class planDialog : public QDialog
{
    Q_OBJECT

public:
    explicit planDialog(QWidget *parent = 0);
    ~planDialog();

    void get_target();//获取计划目标信息
    void get_data();//获取定时提醒信息
    void timer_star();//定时器启动设置
    void time_out();//时间响应

private:
    Ui::planDialog *ui;
    QTimer *m_myTimer = new QTimer();//计时器
    QTime m_Temp;//当前时间
    QString program;//计划项目
    bool ifvedio;//判断是否为视频提醒

signals://自定义信号
    void plansigValue(QString pw,QString ph);
    void vedioshow(int i);

private slots:
    void on_pushButton_2_clicked();
    void TimerResponse();  //时间响应槽，不断检测：判断时间是否到响铃时间
    void on_pushButton_clicked();
};

#endif // PLANDIALOG_H
