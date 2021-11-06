#include "residentlogindlg.h"
#include "ui_residentlogindlg.h"

residentlogindlg::residentlogindlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::residentlogindlg)
{
    ui->setupUi(this);
}

residentlogindlg::~residentlogindlg()
{
    delete ui;
}
