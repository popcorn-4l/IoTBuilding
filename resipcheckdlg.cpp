#include "resipcheckdlg.h"
#include "ui_resipcheckdlg.h"

ResipcheckDlg::ResipcheckDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResipcheckDlg)
{
    ui->setupUi(this);
}

ResipcheckDlg::~ResipcheckDlg()
{
    delete ui;
}

//查找密码
void ResipcheckDlg::on_pushButton_find_clicked()
{
    QString id = ui->lineEdit->text();
    QString gid;
    QString gpwd;

    //读文件
    QFile resfile("restext.txt");
    if(resfile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //获取文件内已注册的账号密码
        QTextStream out(&resfile);
        gid = out.readLine();
        if(id==gid)
        {
            gpwd=out.readLine();
            QMessageBox::information(this,"查找密码",gpwd,QMessageBox::Ok,QMessageBox::Ok);
        }
        else
        {
            QMessageBox::warning(this,"查找密码","该用户不存在!",QMessageBox::Cancel,QMessageBox::Cancel);
        }
    }
}

//删除密码
void ResipcheckDlg::on_pushButton_delete_clicked()
{
    QString id = ui->lineEdit->text();
    QString gid;
    QString gpwd;

    //读文件
    QFile resfile("restext.txt");
    if(resfile.open(QIODevice::ReadWrite))
    {
        //获取文件内已注册的账号密码
        QTextStream out(&resfile);
        gid = out.readLine();
        if(id==gid)
        {
            resfile.remove();
            QMessageBox::information(this,"删除密码","删除成功！",QMessageBox::Ok,QMessageBox::Ok);
        }
        else
        {
            QMessageBox::warning(this,"查找密码","该用户不存在!",QMessageBox::Cancel,QMessageBox::Cancel);
        }
    }
}

//修改密码
//void ResipcheckDlg::on_pushButton_modification_clicked()
//{
//    QString id = ui->lineEdit->text();
//    QString gid;
//    QString gpwd;
//    QString pwd;

//    //读文件
//    QFile resfile("restext.txt");
//    if(resfile.open(QIODevice::ReadWrite))
//    {
//        //获取文件内已注册的账号密码
//        QTextStream out(&resfile);
//        gid = out.readLine();
//        if(id==gid)
//        {
//            gpwd = out.readLine();
//            pwd = QInputDialog::getText(this,"新密码","Please input new pwd",QLineEdit::Normal);
//            out<<left<<pwd<<endl;
//            QMessageBox::information(this,"修改密码","修改成功！",QMessageBox::Ok,QMessageBox::Ok);
//        }
//        else
//        {
//            QMessageBox::warning(this,"查找密码","该用户不存在!",QMessageBox::Cancel,QMessageBox::Cancel);
//        }
//    }
//}
