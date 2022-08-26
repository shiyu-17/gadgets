#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>

static bool createConnection()
{

    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("easybook-3313b0"); //设置数据库主机名
    db.setDatabaseName("qtDB.db"); //设置数据库名
    db.setUserName("liu"); //设置数据库用户名
    db.setPassword("123456"); //设置数据库密码
    db.open(); //打开连接

    QSqlQuery query;

    qDebug()<<"delete!!";
    query.exec("drop table m_data");
    query.exec("drop table day_time");
    query.exec("drop table user_data");

    // 创建m_data表
     query.exec("create table m_data "
               "(p1_index int primary key, m1_time double,m1_month int)");
                //  项目号   时长  月份

     //创建每日运动时间表 day_time
     query.exec("create table day_time "
               "(m2_day int primary key, m2_time double)");

     //创建用户信息表 user_data
     query.exec("create table user_data "
               "(name varchar primary key, sex varchar,age varchar,height varchar,weight double )");


     //添加部分数据便于后续操作

     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(0).arg(8).arg(8));
     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(2).arg(3.5).arg(8));
     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(3).arg(6).arg(8));
     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(4).arg(2).arg(8));
     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(5).arg(4).arg(8));
     query.exec(QString("insert into m_data values('%1','%2','%3')").arg(1).arg(6).arg(8));


     query.exec(QString("insert into day_time values('%1','%2')").arg(13).arg(2));
     query.exec(QString("insert into day_time values('%1','%2')").arg(14).arg(0));
     query.exec(QString("insert into day_time values('%1','%2')").arg(17).arg(3));
     query.exec(QString("insert into day_time values('%1','%2')").arg(19).arg(2));
     query.exec(QString("insert into day_time values('%1','%2')").arg(20).arg(1));
     query.exec(QString("insert into day_time values('%1','%2')").arg(21).arg(2));


    return true;
}

#endif // CONNECTION_H
