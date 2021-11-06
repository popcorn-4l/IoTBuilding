#include "vrviewdlg.h"
#include "ui_vrviewdlg.h"


VRViewDlg::VRViewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VRViewDlg)
{
    ui->setupUi(this);
    ui->widget->setVideoName("E:/QtCode/IoTIntelligentBuilding/myvideo/video1.mp4");
}

VRViewDlg::~VRViewDlg()
{
    delete ui;
}

void VRViewDlg::on_pushButton_video_start_clicked()
{
    ui->widget->play();
}
