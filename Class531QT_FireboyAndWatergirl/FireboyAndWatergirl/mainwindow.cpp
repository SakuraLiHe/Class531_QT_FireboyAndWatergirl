#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QDebug>
#include<QTimer>
#include<QSound>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowIcon(QPixmap(":/image/min.jpg"));
    this->setWindowTitle("森林冰火人");

    //设置遮罩
    shade = new shadewindow;
    shade->setParent(this,Qt::FramelessWindowHint | Qt::Window);
    //shade->setGeometry(0, 0, 1, 1);
    //shade->hide();

    //播放音乐
    QSound *startSound=new QSound(":/image/LevelMusic.wav",this);
    startSound->play();
    startSound->setLoops(100);

    //开始按钮
    MyPushButton *startbtn=new MyPushButton(":/image/play2.png",0.5,0.5);
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,250);

    gam=new game;

    connect(startbtn,&MyPushButton::clicked,[=](){

        startbtn->zoom1();
        startbtn->zoom2();
        //延时
        QTimer::singleShot(100,this,[=](){
            gam->reset();
            this->hide();
            gam->show();
        });
    });
    //set button
    se=new set;
    MyPushButton *setbtn=new MyPushButton(":/image/set-removebg-preview.png",0.15,0.15);
    setbtn->setParent(this);
    setbtn->move(this->width()-190,420);
    connect(se,&set::setBack,this,[=](){
        se->hide();
        shade->hide();
    });
    connect(se,&set::stopmusic,this,[=](){
        startSound->stop();
    });
    connect(se,&set::playmusic,this,[=](){
        startSound->play();
        startSound->setLoops(100);
    });
    connect(setbtn,&MyPushButton::clicked,[=](){
        setbtn->zoom1();
        setbtn->zoom2();
        se->show();
        shade->show();
    });
    //questionButton
    mo=new more;
    MyPushButton *questionbtn=new MyPushButton(":/image/more-removebg-preview.png",0.15,0.15);
    questionbtn->setParent(this);
    questionbtn->move(-110,375);
    connect(mo,&more::moreBack,this,[=](){
        mo->hide();
        shade->hide();
    });
    connect(questionbtn,&MyPushButton::clicked,[=](){
        questionbtn->zoom1();
        questionbtn->zoom2();
        mo->show();
        shade->show();
    });
    //winend
    win=new winend;
    connect(gam,&game::winend1,[=](){
        shade->show();
        win->show();
    });
    connect(win,&winend::CloseWinend,[=](){
       gam->reset();
       gam->hide();
       win->close();
       shade->hide();
       this->show();
    });
    //winend2
    win2=new winend2;
    connect(gam,&game::winend2,[=](){
        shade->show();
        win2->show();
    });
    connect(win2,&winend2::CloseWinend2,[=](){
       gam->reset();
       gam->hide();
       win2->close();
       shade->hide();
       this->show();
    });
    //loseend
    lose=new loseend;
    connect(gam,&game::loseend1,[=](){
        //qDebug()<<"66666666666";
        shade->show();
        lose->show();
    });
    connect(lose,&loseend::menus,[=](){
       gam->reset();
       gam->hide();
       lose->hide();
       shade->hide();
       this->show();
    });
    connect(lose,&loseend::retrys,[=](){
       gam->reset();
       lose->hide();
       shade->hide();
    });
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/start.png");
    painter.drawPixmap(0,0,pix);
}
MainWindow::~MainWindow()
{
    delete ui;
}

