#ifndef RESIDENTLOGINDLG_H
#define RESIDENTLOGINDLG_H

#include <QDialog>

namespace Ui {
class residentlogindlg;
}

class residentlogindlg : public QDialog
{
    Q_OBJECT

public:
    explicit residentlogindlg(QWidget *parent = 0);
    ~residentlogindlg();

private:
    Ui::residentlogindlg *ui;
};

#endif // RESIDENTLOGINDLG_H
