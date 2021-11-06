#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>

namespace Ui {
class Videowidget;
}

class Videowidget : public QWidget
{
    Q_OBJECT

public:
    explicit Videowidget(QWidget *parent = 0);
    ~Videowidget();

private:
    Ui::Videowidget *ui;
};

#endif // VIDEOWIDGET_H
