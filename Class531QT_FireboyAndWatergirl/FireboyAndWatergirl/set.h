#ifndef SET_H
#define SET_H

#include <QMainWindow>

class set : public QMainWindow
{
    Q_OBJECT
public:
    explicit set(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

signals:
    void setBack();
    void stopmusic();
    void playmusic();
};

#endif // SET_H
