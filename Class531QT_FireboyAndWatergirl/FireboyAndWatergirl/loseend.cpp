#include "loseend.h"
#include "ui_loseend.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
loseend::loseend(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loseend)
{
    ui->setupUi(this);
    this->setFixedSize(652,382);
    this->setWindowTitle("winend");
    //this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(1); //窗口整体透明度，0-1 从全透明到不透明
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *menubtn=new MyPushButton(":/image/menu_button.png",1,1);
    menubtn->setParent(this);
    menubtn->move(100,220);
    connect(menubtn,&MyPushButton::clicked,[=]{
        menubtn->zoom1();
        menubtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->menus();
        });
    });
    MyPushButton *retrybtn=new MyPushButton(":/image/retry_button.png",1,1);
    retrybtn->setParent(this);
    retrybtn->move(350,225);
    connect(retrybtn,&MyPushButton::clicked,[=]{
        retrybtn->zoom1();
        retrybtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->retrys();
        });
    });
}

loseend::~loseend()
{
    delete ui;
}
void loseend::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/loseend.png");
    painter.drawPixmap(0,0,652,382,pix);
}
