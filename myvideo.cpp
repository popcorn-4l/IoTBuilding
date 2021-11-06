#include "myvideo.h"
#include "ui_myvideo.h"

myvideo::myvideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myvideo)
{
    ui->setupUi(this);
    mVideoWidget = new QVideoWidget(this);
    mPlayer = new QMediaPlayer;
    mPlayer->setVideoOutput(mVideoWidget);

    //设置视频外的背景为黑色
    mVideoWidget->setAutoFillBackground(true);
    QPalette palette(QPalette::Window,QColor(0,0,0));
    mVideoWidget->setPalette(palette);

    connect(mPlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(OnStateChanged(QMediaPlayer::State)));
    connect(mPlayer,SIGNAL(positionChanged(qint64)),this,SIGNAL(positionChanged(qint64)));
    connect(mPlayer,SIGNAL(durationChanged(qint64)),this,SIGNAL(durationChanged(qint64)));
}

myvideo::~myvideo()
{
    delete ui;
    delete mPlayer;
    delete mVideoWidget;
}

void myvideo::test()
{
    qDebug()<<"test"<<endl;
}



void myvideo::init()
{

}

void myvideo::setVideoName(QString name)
{
    mPlayer->setMedia(QUrl::fromLocalFile(name));//给播放器设置视频路径;
    videoName = name;
    qDebug()<<"success setname"<<endl;
}

QString myvideo::getVideoName()
{
    return videoName;
}

bool myvideo::play()
{
    if(videoName.isEmpty())
    {
        qDebug()<<"empty play"<<endl;
        return 0;
    }
    mPlayer->play();
    qDebug()<<"play"<<endl;
    return 1;
}

bool myvideo::pause()
{
    if(mState != QMediaPlayer::PlayingState)
        return 0;
    mPlayer->pause();
    return 1;
}

bool myvideo::stop()
{
   if(mState == QMediaPlayer::StoppedState)
       return 0;
   mPlayer->stop();
   return 1;
}

quint64 myvideo::getDuration()
{
    return mPlayer->duration();
}

bool myvideo::setPlayPos(quint64 position)
{
    if(mState == QMediaPlayer::StoppedState)
        return 0;
    mPlayer->setPosition(position);
    return 1;
}

quint64 myvideo::getCurrentPlayPos()
{
    return mPlayer->position();
}

void myvideo::setVideoBackColor(QColor color)
{
    QPalette palette(QPalette::Window,color);
    this->setPalette(palette);
}

void myvideo::OnStateChanged(QMediaPlayer::State enumState)
{
    mState = enumState;//获取状态
    emit stateChanged(enumState);//对外发送状态
}

void myvideo::resizeEvent(QResizeEvent *event)
{
    mVideoWidget->setGeometry(0,0,this->width(),this->height());
}
