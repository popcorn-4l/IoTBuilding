#ifndef VISTDLG_H
#define VISTDLG_H

#include "vrviewdlg.h"
#include "parkdlg.h"

#include <QDialog>

namespace Ui {
class VistDlg;
}

class VistDlg : public QDialog
{
    Q_OBJECT

public:
    explicit VistDlg(QWidget *parent = 0);
    ~VistDlg();

private slots:
    void on_btn_v_2vrview_clicked();

    void on_btn_v_2park_clicked();

private:
    Ui::VistDlg *ui;
};

#endif // VISTDLG_H
