#include "vistdlg.h"
#include "ui_vistdlg.h"

VistDlg::VistDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VistDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
}

VistDlg::~VistDlg()
{
    delete ui;
}

void VistDlg::on_btn_v_2vrview_clicked()
{
    VRViewDlg *vrview = new VRViewDlg;
    vrview->show();
}

void VistDlg::on_btn_v_2park_clicked()
{
    ParkDlg *parkdlg = new ParkDlg;
    parkdlg->show();
}
