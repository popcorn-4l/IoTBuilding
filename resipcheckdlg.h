#ifndef RESIPCHECKDLG_H
#define RESIPCHECKDLG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>

namespace Ui {
class ResipcheckDlg;
}

class ResipcheckDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ResipcheckDlg(QWidget *parent = 0);
    ~ResipcheckDlg();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_modification_clicked();

private:
    Ui::ResipcheckDlg *ui;
};

#endif // RESIPCHECKDLG_H
