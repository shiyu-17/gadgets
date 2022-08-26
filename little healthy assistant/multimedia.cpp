#include "multimedia.h"
#include "ui_multimedia.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include<QDebug>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QFileDialog>

Multimedia::Multimedia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Multimedia)
{
    ui->setupUi(this);
    //创建媒体播放器
    m_pPlayer = new QMediaPlayer(this);
    m_pPlayerWidget = new QVideoWidget(this);
    m_pPlayerWidget->resize(600,300);
    m_pPlayer->setVideoOutput(m_pPlayerWidget);
    m_pPlayer->setMedia(QUrl::fromLocalFile("../try01/video1.mp4"));

}


Multimedia::~Multimedia()
{
    delete ui;
}

void Multimedia::media_s(){//暂停 播放

    qDebug()<<"播放/暂停";
    m_palycheck=!m_palycheck;
    if(m_palycheck)
         m_pPlayer->pause();
    else
        m_pPlayer->play();

}
//自定义加载视频
void Multimedia::media_load(){
    qDebug()<<"开始加载视频";
    QFileDialog dialog(this);//新建QFileDialog窗口
    dialog.setFileMode(QFileDialog::AnyFile);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();
    if (!fileNames.empty())
    {
        m_pPlayer->setMedia(QUrl::fromLocalFile(fileNames[0]));//加载相应文件
        m_bReLoad = true;
    }

}
void Multimedia::media_next(){//切换下一条视频

    m_pPlayer->setMedia(QUrl::fromLocalFile("../try01/video2.mp4"));
}

void Multimedia::on_pushButton_clicked()//播放与暂停
{
   media_s();
}

void Multimedia::on_btnload_clicked()//自定义加载视频
{
    media_load();
}

void Multimedia::on_nextpushButton_clicked()
{
    media_next();

}
