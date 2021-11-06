#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //主页面的三个button颜色设置
    ui->btn_0adm->setStyleSheet("background-color:rgb(193,193,193)");
    ui->btn_0user->setStyleSheet("background-color:rgb(193,193,193)");
    ui->btn_0visitor->setStyleSheet("background-color:rgb(193,193,193)");

    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(this->width(),this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_0adm_clicked()
{
    AdmLoginDlg *admlogin = new AdmLoginDlg;
    admlogin->show();
}

void MainWindow::on_btn_0user_clicked()
{
    ResLoginDlg *reslogin = new ResLoginDlg;
    reslogin->show();
}

void MainWindow::on_btn_0visitor_clicked()
{
    VisitLoginDlg *vistlogin = new VisitLoginDlg;
    vistlogin->show();
}


