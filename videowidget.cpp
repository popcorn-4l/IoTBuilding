#include "videowidget.h"
#include "ui_videowidget.h"

Videowidget::Videowidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Videowidget)
{
    ui->setupUi(this);
}

Videowidget::~Videowidget()
{
    delete ui;
}
