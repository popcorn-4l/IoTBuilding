#ifndef ADMLOGINDLG_H
#define ADMLOGINDLG_H

#include "admdlg.h"

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QWidget>

namespace Ui {
class AdmLoginDlg;
}

class AdmLoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AdmLoginDlg(QWidget *parent = 0);
    ~AdmLoginDlg();


private slots:
    void on_btn_1admlog_clicked();

    void on_btn_a_getrange_clicked();

    void on_btn_1admregis_clicked();

    void on_btn_a_getrange2_clicked();

private:
    Ui::AdmLoginDlg *ui;
};

#endif // ADMLOGINDLG_H
