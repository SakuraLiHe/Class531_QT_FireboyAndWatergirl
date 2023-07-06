#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImage,double x,double y)
{
    this->normalImgPath=normalImage;

    QPixmap pix;
    bool ret=pix.load(normalImage);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    this->setIconSize(QSize(pix.width()*x,pix.height()*y));
}
void MyPushButton::zoom1()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
    if(this->y()<400)
    {
        counter++;
    }
    if(counter>=2)
    {
        //qDebug("越界");
        this->move(this->x(),230);
    }
}
void MyPushButton::zoom2()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
