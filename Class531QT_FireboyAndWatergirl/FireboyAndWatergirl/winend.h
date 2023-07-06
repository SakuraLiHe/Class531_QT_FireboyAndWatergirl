#ifndef WINEND_H
#define WINEND_H

#include <QMainWindow>

namespace Ui {
class winend;
}

class winend : public QMainWindow
{
    Q_OBJECT

public:
    explicit winend(QWidget *parent = nullptr);
    ~winend();
    void paintEvent(QPaintEvent*);
private:
    Ui::winend *ui;
signals:
    void CloseWinend();
};

#endif // WINEND_H
