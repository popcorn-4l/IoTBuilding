#ifndef VRVIEWDLG_H
#define VRVIEWDLG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "myvideo.h"

namespace Ui {
class VRViewDlg;
}

class VRViewDlg : public QDialog
{
    Q_OBJECT

public:
    explicit VRViewDlg(QWidget *parent = 0);
    ~VRViewDlg();

private slots:
    void on_pushButton_video_start_clicked();

private:
    Ui::VRViewDlg *ui;
};

#endif // VRVIEWDLG_H
