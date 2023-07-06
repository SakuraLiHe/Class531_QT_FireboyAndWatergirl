#include "set.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QPoint>
#include<QMouseEvent>
#include<QTimer>
set::set(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,700);
    this->setWindowTitle("设置");
    this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(1); //窗口整体透明度，0-1 从全透明到不透明
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    //返回按钮
    MyPushButton *backbtn=new MyPushButton(":/image/back666.png",0.5,0.5);
    backbtn->setParent(this);
    backbtn->move(this->width()*0.5-125,415);

    connect(backbtn,&MyPushButton::clicked,[=]{
        backbtn->zoom1();
        backbtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->setBack();
        });

    });
    //music
    int num=0;
    MyPushButton *musicbtn=new MyPushButton(":/image/music666.png",0.4,0.4);
    musicbtn->setParent(this);
    musicbtn->move(this->width()*0.5-100,230);
    connect(musicbtn,&MyPushButton::clicked,[=]()mutable{
        num++;
        if(num%2==1)
        emit this->stopmusic();
        else
        emit this->playmusic();
        musicbtn->zoom1();
        musicbtn->zoom2();
    });
}
void set::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/set2.png");
    painter.drawPixmap(210,210,600,326,pix);
}

