#ifndef WINEND2_H
#define WINEND2_H

#include <QMainWindow>

namespace Ui {
class winend2;
}

class winend2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit winend2(QWidget *parent = nullptr);
    ~winend2();
    void paintEvent(QPaintEvent*);

private:
    Ui::winend2 *ui;
signals:
    void CloseWinend2();
};

#endif // WINEND2_H
