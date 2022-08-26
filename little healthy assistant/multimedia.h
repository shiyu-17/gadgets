#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <QDialog>
#include <QDebug>
class QMediaPlayer;
class QVideoWidget;

namespace Ui {
class Multimedia;
}

class Multimedia : public QDialog
{
    Q_OBJECT

public:
    explicit Multimedia(QWidget *parent = 0);
    ~Multimedia();

    bool            m_bReLoad;
    void media_s();//暂停 播放
    void media_load();//自定义加载视频
    void media_next();//切换下一条视频

private slots:
    void on_pushButton_clicked();//暂停 播放按钮

    void on_btnload_clicked();//自定义加载视频

    void on_nextpushButton_clicked();//切换下一条视频

private:
    Ui::Multimedia *ui;

    QVideoWidget    *m_pPlayerWidget;
    QMediaPlayer    *m_pPlayer;
    bool m_palycheck = false;//播放暂停/开始判断



};

#endif // MULTIMEDIA_H
