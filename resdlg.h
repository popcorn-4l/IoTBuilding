#ifndef RESDLG_H
#define RESDLG_H

#include <QDialog>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>

#include "parkdlg.h"

namespace Ui {
class ResDlg;
}

class ResDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ResDlg(QWidget *parent = 0);
    ~ResDlg();

private slots:
    void on_btn_r_2checkwae_clicked();

    void on_btn_r_2shenbao_clicked();

    void on_btn_r_2securty_clicked();

    void on_btn_r_2smoke_clicked();

    void on_btn_r_2tem_clicked();

    void on_btn_r_2park_clicked();

private:
    Ui::ResDlg *ui;
};

#endif // RESDLG_H
