#include "winend2.h"
#include "ui_winend2.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
winend2::winend2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winend2)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setFixedSize(680,367);
    this->setWindowTitle("winend");
    //this->setWindowModality(Qt::ApplicationModal);
    this->setWindowOpacity(1); //窗口整体透明度，0-1 从全透明到不透明
    this->setWindowFlags(Qt::FramelessWindowHint); //设置无边框风格
    this->setAttribute(Qt::WA_TranslucentBackground); //设置背景透明，允许鼠标穿透
    MyPushButton *continuebtn2=new MyPushButton(":/image/continue_button.png",1,1);
    continuebtn2->setParent(this);
    continuebtn2->move(225,225);
    connect(continuebtn2,&MyPushButton::clicked,[=]{
        continuebtn2->zoom1();
        continuebtn2->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            emit this->CloseWinend2();
        });
    });
}

winend2::~winend2()
{
    delete ui;
}
void winend2::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/winend2.png");
    painter.drawPixmap(0,0,680,367,pix);
}
