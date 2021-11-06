#include "parkdlg.h"
#include "ui_parkdlg.h"

ParkDlg::ParkDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParkDlg)
{
    ui->setupUi(this);
}

ParkDlg::~ParkDlg()
{
    delete ui;
}
