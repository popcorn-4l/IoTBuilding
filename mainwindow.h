#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "admlogindlg.h"
#include "reslogindlg.h"
#include "visitlogindlg.h"

#include <QMainWindow>
#include <QInputDialog>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_0adm_clicked();

    void on_btn_0user_clicked();

    void on_btn_0visitor_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
