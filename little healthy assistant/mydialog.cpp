#include "mydialog.h"
#include "ui_mydialog.h"
#include <QtSql>
#include <QtGui>
#include <QDebug>

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);

}

myDialog::~myDialog()
{
    delete ui;
}
//获取基本信息
void myDialog::get_mdata(){
    weight = ui->kgSpinBox->value();//获取值
    height = ui->cmLineEdit->text();
    name = ui->nameLineEdit->text();
    sex = ui->sexComboBox->currentText();
    age = ui->ageLineEdit->text();
    if(age<=0||weight<0||name<0){
        qDebug()<<"输入无效信息";
        QLabel *label = new QLabel();
        label->resize(180,30);
        label->setText(QString("输入无效信息！！！"));
        label->show();
    }
}

void myDialog::on_pushButton_clicked()
{
    get_mdata();
    emit mysigValue(weight,height);//发送
    load_data();
}

//用户信息载入数据库
void myDialog::load_data(){
    QSqlQuery query;
    query.exec(QString("insert into user_data values('%1','%2','%3','%4','%5')").arg(name).arg(sex).arg(age).arg(height.arg(weight)));
}

