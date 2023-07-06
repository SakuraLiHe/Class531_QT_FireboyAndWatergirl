#ifndef LOSEEND_H
#define LOSEEND_H

#include <QMainWindow>

namespace Ui {
class loseend;
}

class loseend : public QMainWindow
{
    Q_OBJECT

public:
    explicit loseend(QWidget *parent = nullptr);
    ~loseend();
    void paintEvent(QPaintEvent*);

private:
    Ui::loseend *ui;
signals:
    void menus();
    void retrys();
};

#endif // LOSEEND_H
