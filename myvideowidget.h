#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QWidget>

namespace Ui {
class myqvideowidget;
}

class myqvideowidget : public QWidget
{
    Q_OBJECT

public:
    explicit myqvideowidget(QWidget *parent = 0);
    ~myvideowidget();

    void test();
private:
    Ui::myqvideowidget *ui;
};

#endif // MYVIDEOWIDGET_H
