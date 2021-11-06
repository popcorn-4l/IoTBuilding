#ifndef MYVIDEO_H
#define MYVIDEO_H

#include <QWidget>
#include <QDebug>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QObject>

namespace Ui {
class myvideo;
}

class myvideo : public QWidget
{
    Q_OBJECT

public:
    explicit myvideo(QWidget *parent = 0);
    ~myvideo();
    void test();
    void setVideoName(QString name);//设置视频的名字
    QString getVideoName();//获取导入的视频名字

    void init();    //播放初始化，初始化一些状态

    bool play();
    bool pause();
    bool stop();

    quint64 getDuration();//获取视频时长
    bool setPlayPos(quint64 position);//设置视频播放位置
    quint64 getCurrentPlayPos();//获取当前视频位置

    void setVideoBackColor(QColor color);



signals:
    void stateChanged(QMediaPlayer::State);
    void positionChanged(qint64);
    void durationChanged(qint64);

public slots:
    void OnStateChanged(QMediaPlayer::State enumState);

private:
    Ui::myvideo *ui;
    QVideoWidget *mVideoWidget;
    QMediaPlayer *mPlayer;
    QString videoName;
    QMediaPlayer::State mState;

    void resizeEvent(QResizeEvent *event);
};

#endif // MYVIDEO_H
