#include "widget.h"
#include <QApplication>
#include <QtGui>
#include "connection.h"
//#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 必须在创建数据库之前使用，不然无法在数据库中使用中文
//    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    if(!createConnection()) return 0;

    Widget w;
    w.show();

    return a.exec();
}
