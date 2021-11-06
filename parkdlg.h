#ifndef PARKDLG_H
#define PARKDLG_H

#include <QDialog>

namespace Ui {
class ParkDlg;
}

class ParkDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ParkDlg(QWidget *parent = 0);
    ~ParkDlg();

private:
    Ui::ParkDlg *ui;
};

#endif // PARKDLG_H
