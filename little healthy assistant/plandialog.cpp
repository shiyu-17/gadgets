#include "plandialog.h"
#include "ui_plandialog.h"
#include <QDebug>


planDialog::planDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planDialog)
{
    ui->setupUi(this);
    connect(m_myTimer, SIGNAL(timeout()), this, SLOT(TimerResponse()));
    ifvedio=false;
}

planDialog::~planDialog()
{
    delete ui;
}
//计划目标信息
void planDialog::get_target(){
    QString pw = ui->pwLineEdit->text();//获取值
    QString ph = ui->mbLineEdit->text();
    emit plansigValue(pw,ph);//发送

}

//获取定时提醒信息
void planDialog::get_data(){
    program = ui->pComboBox->currentText();//获取运动项目
    int number = ui->pComboBox->currentIndex();
    qDebug() << number;
    if(number==0){
        ifvedio=true;
        qDebug()<<"视频提醒";
    }

}
//定时器启动设置
void planDialog::timer_star(){
    m_Temp = ui->tDateTimeEdit->time();//获取提醒时间
    m_myTimer->start(500);//计时器开始计时，每隔0.5毫秒发出信号
}
//信号溢出提醒
void planDialog::time_out(){
    if(m_Temp.hour() == QTime::currentTime().hour()&&
            m_Temp.minute() == QTime::currentTime().minute())
     {
        qDebug() << "提醒";
        if(ifvedio){
            emit vedioshow(1);//发射视频弹窗信号
            ifvedio=false;
        }
        else{
            QLabel *label = new QLabel();
            label->resize(180,30);
            label->setText(QString("开始'%1'吧！！！").arg(program));
            label->show();
        }
        m_myTimer->stop();

    }
}
void planDialog::on_pushButton_2_clicked()//计划目标信息
{
    get_target();
}

void planDialog::TimerResponse()
{
   time_out();
}

void planDialog::on_pushButton_clicked()
{
    get_data();
    timer_star();
    qDebug() << "计时开始！";
}
