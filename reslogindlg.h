#ifndef RESLOGINDLG_H
#define RESLOGINDLG_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFile>
#include <QTextStream>

namespace Ui {
class ResLoginDlg;
}

class ResLoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ResLoginDlg(QWidget *parent = 0);
    ~ResLoginDlg();

private slots:
    void on_btn_1reslog_clicked();

    void on_btn_r_getrange_clicked();

    void on_btn_1resregis_clicked();

    void on_btn_r_getrange2_clicked();

private:
    Ui::ResLoginDlg *ui;
};

#endif // RESLOGINDLG_H
