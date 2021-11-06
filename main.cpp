#include "mainwindow.h"
#include <QApplication>

#include <QWidget>
#include <QPalette>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QApplication::setStyle("windows");

    //更改主页背景图
    w.setAutoFillBackground(true);
    //设置图片
    QPixmap pixmap = QPixmap(":/BackGroundIimages/backimage.jpg").scaled(w.size());
    QPalette palette(w.palette());
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    w.setPalette(palette);
    //设置窗口不可改变大小
    w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint);
    w.setFixedSize(w.width(),w.height());
    w.show();

    //管理员注册登录页
//    AdmLoginDlg al;
//    al.setAutoFillBackground(true);
//    QPixmap pixmap_al = QPixmap(":/BackGroundIimages/backimage.jpg").scaled(al.size());
//    QPalette palette_al(al.palette());
//    palette_al.setBrush(QPalette::Background,QBrush(pixmap_al));
//    al.setPalette(palette_al);
//    al.setWindowFlags(al.windowFlags()&~Qt::WindowMaximizeButtonHint);
//    al.show();

    //住户注册登录页

    //访客注册登录页

    //管理员页面

    //住户页面

    //访客页面



    return a.exec();
}
