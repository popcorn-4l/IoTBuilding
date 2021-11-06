#include "admlogindlg.h"
#include "ui_admlogindlg.h"
#include <QTime>
#include <QInputDialog>

AdmLoginDlg::AdmLoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdmLoginDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
}

AdmLoginDlg::~AdmLoginDlg()
{
    delete ui;
}

/*
 * *ToolBox1
 * *管理员登录界面*
 * *触发条件： “登录”按钮 clicked();
 *
 * 管理员账号密码文件名:aptext.txt
 *
 * UI控件对应名
 * btn_1admlog     “登录”按钮
 * btn_a_getrange  “获取验证码..”按钮
 * lineEdit    id      账号
 * lineEdit_2  pwd    密码
 * lineEdit_3  grange   验证码
 *
*/
int range_log;
void AdmLoginDlg::on_btn_1admlog_clicked()
{
    //账号密码判断
    //账号、密码、验证码不得为空
    QString id = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
    int grange = ui->lineEdit_3->text().toInt();
    //文件读取的帐号密码
    QString gid;
    QString gpwd;

    //三数据都不为空 - 填写正确
    if((id!=NULL)&&(pwd!=NULL)&&(grange!=NULL))
    {
        if(range_log == grange)
        {
            //读文件
            QFile file("aptext.txt");
            if(file.open(QIODevice::ReadOnly|QIODevice::Text))
            {
                //获取文件内已注册的账号密码
                QTextStream out(&file);
                gid = out.readLine();
                gpwd = out.readLine();
            }

            if((id==gid) && (pwd == gpwd))
            {
                QMessageBox::information(this,"login","登录成功！",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
                //成功后删除输入框
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                //跳转到管理员操作主界面
                AdmDlg *admdlg = new AdmDlg;
                admdlg->show();

            }
            else
            {
                QMessageBox::warning(this,"false","账号或密码有误，请重试！",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
                //登录失败 -> 账号密码有误 -> 清空输入框
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
            }
        }
        else
        {
            QMessageBox::warning(this,"false","验证码有误，请重试！",QMessageBox::Cancel,QMessageBox::Cancel);
        }

    }
    else
    {
        QMessageBox::warning(this,"false","账号、密码、验证码任一项都不得为空，请重试！",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//生成登录需要的验证码
void AdmLoginDlg::on_btn_a_getrange_clicked()
{
    //生成一个随机数
    qsrand(QTime::currentTime().msec());//随机数初始化

    //将随机数存起来
    //用于messagebox弹窗显示
    //
    range_log = qrand()%10000+1000;
    QString text = QString::number(range_log);

    //生成弹窗
    QInputDialog::getText(this,"Range","get range",QLineEdit::Normal,text);

    //随机数填入登录界面的随机数输入框 = 自动复制随机数
    //lineEdit_3 验证码输入框
    ui->lineEdit_3->setText(text);
}

/*
 * *ToolBox2
 * *管理员注册界面*
 * *触发条件： “注册”按钮 clicked();
 *
 * 管理员账号密码文件名:aptext.txt
 *
 * UI控件对应名
 * btn_1admregis     “注册”按钮
 * btn_a_getrange2   “获取验证码..”按钮
 * lineEdit_4  id     账号
 * lineEdit_5  pwd1   密码
 * lineEdit_6  pwd2   确认密码
 * lineEdit_7  inv    邀请码【6666】
 * lineEdit_8  grange  验证码
 *
*/
int range_res;
void AdmLoginDlg::on_btn_1admregis_clicked()
{
    //lineEdit4 5 6 7 8
    //账号 密码 确认密码 邀请码[6666] 验证码
    QString id = ui->lineEdit_4->text();
    QString pwd1 = ui->lineEdit_5->text();
    QString pwd2 = ui->lineEdit_6->text();
    QString inv = ui->lineEdit_7->text();
    int grange = ui->lineEdit_8->text().toInt();

    //判断数据框是否为空
    if((id != NULL)&&(pwd1!=NULL)&&(pwd2!=NULL)&&(inv!=NULL)&&(grange!=NULL))
    {
        if(range_res==grange)
        {
            if((inv=="6666") && (pwd1 == pwd2))
            {
                    //账号密码写入文件
                    QFile file("aptext.txt");
                    if(file.open(QFile::ReadWrite))
                    {
                        QTextStream out(&file);
                        out<<left<<ui->lineEdit_4->text()<<endl;
                        out<<QObject::tr("")<<qSetFieldWidth(0)<<left<<ui->lineEdit_5->text()<<endl;
                        out<<QObject::tr("")<<qSetFieldWidth(0)<<left<<ui->lineEdit_6->text()<<endl;
                        out<<QObject::tr("")<<qSetFieldWidth(0)<<left<<endl;
                        QMessageBox::information(this,"注册","注册成功！",QMessageBox::Ok,QMessageBox::Ok);
                        //成功后删除输入框
                        ui->lineEdit_5->clear();
                        ui->lineEdit_6->clear();
                        ui->lineEdit_7->clear();
                        ui->lineEdit_8->clear();
                        //跳转到管理员操作主界面
                        AdmDlg *admdlg = new AdmDlg;
                        admdlg->show();
                    }

            }
            else if((inv!="6666") && (pwd1 == pwd2))
            {
                QMessageBox::warning(this,"false","您未被邀请为管理员，请重试！",QMessageBox::Ok,QMessageBox::Ok);
            }
            else if((inv=="6666") && (pwd1 != pwd2))
            {
                QMessageBox::warning(this,"false","确认密码有误，请重试！",QMessageBox::Ok,QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::warning(this,"false","验证码有误，请重试！",QMessageBox::Cancel,QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::warning(this,"false","账号、密码、验证码任一项都不得为空，请重试！",QMessageBox::Ok,QMessageBox::Ok);
    }
}

//生成注册需要的验证码
void AdmLoginDlg::on_btn_a_getrange2_clicked()
{
    //生成一个随机数
    qsrand(QTime::currentTime().msec());//随机数初始化

    //将随机数存起来
    //用于messagebox弹窗显示
    //int range_res;
    range_res = qrand()%10000+1000;
    QString text = QString::number(range_res);

    //生成弹窗
    QInputDialog::getText(this,"Range","get range",QLineEdit::Normal,text);

    //随机数填入登录界面的随机数输入框 = 自动复制随机数
    //lineEdit_8 验证码输入框
    ui->lineEdit_8->setText(text);
}
