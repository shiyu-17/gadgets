#include "addialog.h"
#include "ui_addialog.h"
#include <QtSql>
#include <QtGui>


addialog::addialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addialog)
{
    ui->setupUi(this);

}

addialog::~addialog()
{
    delete ui;
}
//获取打卡信息
void addialog::get_data(){

    QDate day = ui->tDateTimeEdit->date();
    pm_day = day.day();
    pm_month =day.month();
    if(pm_day<=0||pm_day>31||pm_month<0||pm_month>12){
        qDebug()<<"输入无效信息";
        QLabel *label = new QLabel();
        label->resize(180,30);
        label->setText(QString("输入无效信息！！！"));
        label->show();
    }
    pm_index = ui->proComboBox->currentIndex();
    pm_time = ui->doubleSpinBox->value();
}

//将打卡数据写入数据库
void addialog::load_data(){
    get_data();//获取打卡信息
    QSqlQuery query;
    //插入day_time表
    if(query.exec(QString("select * from day_time where m2_day = '%1'").arg(pm_day))){
        query.next();
        double temp2=query.value(1).toDouble()+pm_time;
        qDebug()<<"already exist this day";
        query.exec(QString("update day_time set m2_time = '%1' where m2_day = '%2'").arg(temp2).arg(pm_day));
    }
    else {
        query.exec(QString("insert into day_time values('%1','%2')").arg(pm_day).arg(pm_time));
        qDebug()<<"success insert this day";
    }
    //插入m_data表
    if(query.exec(QString("select * from m_data where p1_index = '%1'").arg(pm_index))){
        query.next();
        double temp1=query.value(1).toDouble()+pm_time;
        qDebug()<<"already exist this program";
        query.exec(QString("update m_data set m1_time = '%1' where p1_index = '%2'").arg(temp1).arg(pm_index));
    }
    else {
        query.exec(QString("insert into m_data values('%1','%2','%3')").arg(pm_index).arg(pm_time).arg(pm_month));
    qDebug()<<"success insert this program";}



    //临时 ！！！！！！！！！！！！！
    query.exec(QString("insert into m_data values('%1','%2','%3')").arg(pm_index).arg(pm_time).arg(pm_month));
    query.exec(QString("insert into day_time values('%1','%2')").arg(pm_day).arg(pm_time));
    query.first();
}

void addialog::on_pushButton_clicked()
{
    load_data();
//    Widget::getdata();
//    Widget::show_data();
}
