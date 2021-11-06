#include "visitlogindlg.h"
#include "ui_visitlogindlg.h"

#include "vistdlg.h"

#include <QTime>
#include <QInputDialog>

VisitLoginDlg::VisitLoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitLoginDlg)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());
}

VisitLoginDlg::~VisitLoginDlg()
{
    delete ui;
}

/*
 * *ToolBox1
 * *访客登录界面*
 * *触发条件： “登录”按钮 clicked();
 *
 * 访客账号密码文件名:visitext.txt
 *
 * UI控件对应名
 * btn_1vistlog    登录
 * btn_v_getrange  获得随机数
 * lineEdit        账号
 * lineEdit_2      密码
 * lineEdit_3      随机数
 *
*/
int range_vlog;
void VisitLoginDlg::on_btn_1vistlog_clicked()
{
    QString id = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
    //账号密码判断
    //账号、密码、验证码不得为空
    int grange = ui->lineEdit_3->text().toInt(); //rangein - lineEdit_3 里的随机数 - 自动复制过来的

    QString gid;
    QString gpwd;

    //三数据都不为空 - 填写正确
    if((id != NULL)&&(pwd!=NULL)&&(grange!=NULL))
    {
        if(range_vlog == grange)
        {
            //读文件
            QFile visfile("visitext.txt");
            if(visfile.open(QIODevice::ReadOnly|QIODevice::Text))
            {
                //获取文件内已注册的账号密码
                QTextStream out(&visfile);
                gid = out.readLine();
                gpwd = out.readLine();
            }

            if((id==gid) && (pwd == gpwd))
            {
                QMessageBox::information(this,"login","登录成功！",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
                //登录成功后删除输入框
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                //跳转至访客操作主界面
                VistDlg *vistdlg = new VistDlg;
                vistdlg->show();
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

//生成访客登录时的随机数
void VisitLoginDlg::on_btn_v_getrange_clicked()
{
    //生成一个随机数
    qsrand(QTime::currentTime().msec());//随机数初始化

    //将随机数存起来
    //用于messagebox弹窗显示
    //int range_vlog;
    range_vlog = qrand()%10000+1000;
    QString text = QString::number(range_vlog);

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
 * 住户账号密码文件名:visitext.txt
 *
 * UI控件对应名
 * btn_1vistregis     “注册”按钮
 * btn_v_getrange2   “获取验证码..”按钮
 * lineEdit_4  id     账号
 * lineEdit_5  pwd1   密码
 * lineEdit_6  pwd2   确认密码
 * lineEdit_7  grange   确认密码
 *
*/
int range_vres;
void VisitLoginDlg::on_btn_1vistregis_clicked()
{
    //lineEdit4 5 6 7 8
    //账号 密码 确认密码 邀请码[6666] 验证码
    QString id = ui->lineEdit_4->text();
    QString pwd1 = ui->lineEdit_5->text();
    QString pwd2 = ui->lineEdit_6->text();
    int grange = ui->lineEdit_7->text().toInt();

    //判断数据框是否为空
    if((id != NULL)&&(pwd1!=NULL)&&(pwd2!=NULL)&&(grange!=NULL))
    {
        if(range_vres == grange)
        {
            if(pwd1 == pwd2)
            {
                //账号密码写入文件
                QFile visfile("visitext.txt");
                if(visfile.open(QFile::WriteOnly|QFile::Truncate))
                {
                    QTextStream out(&visfile);
                    out<<left<<ui->lineEdit_4->text()<<endl;
                    out<<QObject::tr("")<<qSetFieldWidth(0)<<left<<ui->lineEdit_5->text()<<endl;
                    out<<QObject::tr("")<<qSetFieldWidth(0)<<left<<ui->lineEdit_6->text()<<endl;
                    QMessageBox::information(this,"登录","注册成功！",QMessageBox::Ok,QMessageBox::Ok);
                    //成功后删除输入框
                    ui->lineEdit_5->clear();
                    ui->lineEdit_6->clear();
                    ui->lineEdit_7->clear();
                }
            }
            else if(pwd1 != pwd2)
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

//生成访客注册时的随机数
void VisitLoginDlg::on_btn_v_getrange2_clicked()
{
    //生成一个随机数
    qsrand(QTime::currentTime().msec());//随机数初始化

    //将随机数存起来
    //用于messagebox弹窗显示
    //int range_vres;
    range_vres = qrand()%10000+1000;
    QString text = QString::number(range_vres);

    //生成弹窗
    QInputDialog::getText(this,"Range","get range",QLineEdit::Normal,text);

    //随机数填入登录界面的随机数输入框 = 自动复制随机数
    //lineEdit_8 验证码输入框
    ui->lineEdit_7->setText(text);
}
