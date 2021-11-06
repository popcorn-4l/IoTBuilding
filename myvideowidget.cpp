#include "myvideowidget.h"
#include "ui_myvideowidget.h"

myqvideowidget::myqvideowidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myqvideowidget)
{
    ui->setupUi(this);
}

myqvideowidget::~myqvideowidget()
{
    delete ui;
}


void myqvideowidget::test()
{
    qDebug()<<"test success"<<endl;
}
