#include "resdlg.h"
#include "ui_resdlg.h"

#include <QTime>
#include <QInputDialog>

ResDlg::ResDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
}

ResDlg::~ResDlg()
{
    delete ui;
}

//查看wae.txt
void ResDlg::on_btn_r_2checkwae_clicked()
{
    QFile waefile("waefile.txt");

    if(waefile.open(QFile::ReadWrite))
    {
        QTextStream out(&waefile);//获取文件内已注册的账号密码
        QString id = out.readLine();
        QMessageBox::information(this,"水费",out.readLine(),QMessageBox::Ok,QMessageBox::Ok);
        QMessageBox::information(this,"电费",out.readLine(),QMessageBox::Ok,QMessageBox::Ok);
    }
}

void ResDlg::on_btn_r_2shenbao_clicked()
{
    QFile fixfile("fixfile.txt");

    if(fixfile.open(QFile::ReadWrite))
    {
        QTextStream out(&fixfile);
        //点击按钮后跳出水电费弹窗，计入水电费
        QString need = QInputDialog::getText(this,"id","Please input your need",QLineEdit::Normal);
        //写入文档
        out<<need<<endl;
        QMessageBox::information(this,"维修申报表","申报成功",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//安全时间
void ResDlg::on_btn_r_2securty_clicked()
{
    QFile securetimefile("securetimefile.txt");

    if(securetimefile.open(QFile::ReadWrite))
    {
        QTextStream out(&securetimefile);
        //点击按钮后跳出设置安全事件弹窗
        QString need = QInputDialog::getText(this,"securetime","Please input securetime",QLineEdit::Normal);
        //写入文档
        out<<need<<endl;
        QMessageBox::information(this,"安全时间设置","设置成功",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//烟雾
void ResDlg::on_btn_r_2smoke_clicked()
{
    QFile smokefile("smokefile.txt");

    if(smokefile.open(QFile::ReadWrite))
    {
        QTextStream out(&smokefile);
        //点击按钮后跳出烟雾阈值设置弹窗
        QString need = QInputDialog::getText(this,"烟雾阈值","请输入烟雾阈值",QLineEdit::Normal);
        //写入文档
        out<<need<<endl;
        QMessageBox::information(this,"烟雾阈值设置","设置成功",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//温度
void ResDlg::on_btn_r_2tem_clicked()
{
    QFile tmpfile("tmpfile.txt");

    if(tmpfile.open(QFile::ReadWrite))
    {
        QTextStream out(&tmpfile);
        //点击按钮后跳出温度阈值设置弹窗
        QString need = QInputDialog::getText(this,"温度阈值","请输入温度阈值",QLineEdit::Normal);
        //写入文档
        out<<need<<endl;
        QMessageBox::information(this,"温度阈值设置","设置成功",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//停车场
//临时停车
//月卡、年卡
void ResDlg::on_btn_r_2park_clicked()
{
    //跳转至付费停车专门页
    //数据库登记用户信息
    //扫码登记操作
    ParkDlg *parkdlg = new ParkDlg;
    parkdlg->show();

}

//快递物流
//void ResDlg::on_btn_r_2wuliu_clicked()
//{
//    //文件读取
//    //条码识别登记至文件

//}
