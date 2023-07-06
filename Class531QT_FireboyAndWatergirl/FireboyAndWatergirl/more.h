#ifndef MORE_H
#define MORE_H

#include <QMainWindow>

class more : public QMainWindow
{
    Q_OBJECT
public:
    explicit more(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void moreBack();
};

#endif // MORE_H
