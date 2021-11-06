#ifndef VISITLOGINDLG_H
#define VISITLOGINDLG_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFile>
#include <QTextStream>

namespace Ui {
class VisitLoginDlg;
}

class VisitLoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit VisitLoginDlg(QWidget *parent = 0);
    ~VisitLoginDlg();

private slots:
    void on_btn_1vistlog_clicked();

    void on_btn_v_getrange_clicked();

    void on_btn_1vistregis_clicked();

    void on_btn_v_getrange2_clicked();

private:
    Ui::VisitLoginDlg *ui;
};

#endif // VISITLOGINDLG_H
