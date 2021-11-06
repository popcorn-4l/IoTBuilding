#include "admdlg.h"
#include "ui_admdlg.h"

AdmDlg::AdmDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdmDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
}

AdmDlg::~AdmDlg()
{
    delete ui;
}

//水电费按钮
void AdmDlg::on_btn_a_2wae_clicked()
{
    QFile waefile("waefile.txt");

    if(waefile.open(QFile::ReadWrite))
    {
        QTextStream out(&waefile);
        //点击按钮后跳出水电费弹窗，计入水电费
        QString id = QInputDialog::getText(this,"id","Please input resident's id",QLineEdit::Normal);
        QString water = QInputDialog::getText(this,"water","Please input water bill",QLineEdit::Normal,"000");
        QString ele = QInputDialog::getText(this,"ele","Please input ele bill",QLineEdit::Normal);
        //写入文档
        out<<id<<endl;
        out<<water<<endl;
        out<<ele<<endl;
        QMessageBox::information(this,"水电费发布","发布成功",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//维修申报查看按钮
void AdmDlg::on_btn_a_2service_clicked()
{
    QFile fixfile("fixfile.txt");

    if(fixfile.open(QFile::ReadWrite))
    {
        QTextStream out(&fixfile);
        QMessageBox::information(this,"用户维修申报情况",out.readLine(),QMessageBox::Ok,QMessageBox::Ok);
    }
}

//入住登记
//文件内有数据即为1
//搞个文件，查看数据个数即为当前入住人数
void AdmDlg::on_btn_a_2checkin_clicked()
{
    QString gid;
    //读用户登记文件
    QFile resfile("restext.txt");
    if(resfile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //获取文件内已注册的账号密码
        QTextStream out(&resfile);
        gid = out.readLine();
        if(gid.isNull())
        {
            QMessageBox::information(this,"当前在住详情","当前住户为 ： 0  户",QMessageBox::Ok,QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(this,"当前在住详情","当前住户为 ： 1  户",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
}


//用户账号密码查删
void AdmDlg::on_btn_a_2ipcheck_clicked()
{
    //跳转到用户账号密码操作页面 resipcheck.ui
    ResipcheckDlg *resipcheck = new ResipcheckDlg;
    resipcheck->show();
}

