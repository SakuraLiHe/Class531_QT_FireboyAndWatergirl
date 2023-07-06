#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImage,double x,double y);
    QString normalImgPath;
    QString pressImgPath;

    void zoom1();
    void zoom2();
    int counter=0;


};

#endif // MYPUSHBUTTON_H
