#ifndef ADMDLG_H
#define ADMDLG_H

#include <QDialog>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>

#include "resipcheckdlg.h"

namespace Ui {
class AdmDlg;
}

class AdmDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AdmDlg(QWidget *parent = 0);
    ~AdmDlg();

private slots:
    void on_btn_a_2wae_clicked();

    void on_btn_a_2service_clicked();

    void on_btn_a_2ipcheck_clicked();

    void on_btn_a_2checkin_clicked();

private:
    Ui::AdmDlg *ui;
};

#endif // ADMDLG_H
