#include "game.h"
#include "ui_game.h"
#include <QLabel>
#include <QTimer>
#include <QEvent>
#include <QDebug>
#include <QTimerEvent>
#include <QKeyEvent>
#include "windows.h"
#include <QString>
#include<QMessageBox>
game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap(":/image/min.jpg"));
    this->setWindowTitle("森林冰火人");
    id1=startTimer(10);
    ui->fireman->move(55,537);
    ui->watergirl->move(55,445);
    x[0]=55,y[0]=537,x[1]=55,y[1]=445;
    ay[0]=0,ay[1]=0,vy[0]=0,vy[1]=0,vx[0]=0,vx[1]=0;
    minx[0]=35,miny[0]=510,maxy[0]=537,maxx[0]=765;
    minx[1]=35,miny[1]=430,maxy[1]=452,maxx[1]=765;
    rednumber = 0;
    bluenumber = 0;
    move_=1;
    memset(redget,false,sizeof (redget));
    memset(blueget,false,sizeof (blueget));
}

game::~game()
{
    delete ui;
}
bool game::getMaxAndMin(int nowx, int nowy,int fow)
{
    if(nowx>=30&&nowx<=275&&nowy>=510&&nowy<=537){
                minx[fow]=35,miny[fow]=510,maxy[fow]=537,maxx[fow]=680;
            }
            else if(nowx>=30&&nowx<=275&&nowy>=430&&nowy<=452){
                minx[fow]=35,miny[fow]=430,maxy[fow]=452,maxx[fow]=680;
            }
            else if(nowx>=275&&nowx<=300&&nowy>=430&&nowy<=452){
                minx[fow]=35,miny[fow]=430,maxy[fow]=537,maxx[fow]=680;
            }
            else if(nowx>=280&&nowx<=300&&nowy>452&&nowy<520){
                minx[fow]=280,miny[fow]=430,maxy[fow]=537,maxx[fow]=775;
            }
            else if(nowx>=280&&nowx<=300&&nowy>=520&&nowy<=537){
                minx[fow]=35,miny[fow]=430,maxy[fow]=537,maxx[fow]=775;
            }

            else if(nowx>=300&&nowx<=335&&nowy>=440&&nowy<=537){
                minx[fow]=280,miny[fow]=430,maxy[fow]=537,maxx[fow]=355;
                if(nowy>=430&&nowy<=465){
                    miny[fow]=430+(nowx-300);
                    maxx[fow]=300+(nowy-430);
                }
            }
            else if(nowx>=335&&nowx<=455&&nowy>=475&&nowy<=550){
                minx[fow]=35,miny[fow]=475,maxy[fow]=537,maxx[fow]=690;
                if(nowx>=365&&nowx<=455){
                    if(fow==0){
                        if(nowx>=365&&nowx<=385){
                            if(nowy>=537&&nowy<=547){
                                maxy[fow]=537+(nowx-365)/2;
                                minx[fow]=365+(nowy-537)*2;
                            }
                        }
                        else if(nowx>=385&&nowx<=435){
                            maxy[fow]=547;
                        }
                        else if(nowx>=435&&nowx<=455){
                            if(nowy>=537&&nowy<=547){
                                maxx[fow]=455-(nowy-537)*2;
                                maxy[fow]=547-(nowx-435)/2;
                            }
                        }
                    }
                    else if(fow==1&&nowy==537) {
                        move_ = 0;
                        return false;
                    }
                }
            }
            else if(nowx>455&&nowx<475&&nowy>=475&&nowy<=537){
                minx[fow]=35,miny[fow]=475,maxy[fow]=537,maxx[fow]=690;
                if(nowy>=475&&nowy<=495){
                    miny[fow]=475+(nowx-455);
                    maxx[fow]=455+(nowy-475);
                }
            }
            else if(nowx>=475&&nowx<=520&&nowy<=537&&nowy>=490){
                minx[fow]=35,miny[fow]=495,maxy[fow]=537,maxx[fow]=695;
            }
            else if(nowx>=520&&nowx<=540&&nowy<=537&&nowy>=475){
                minx[fow]=35,miny[fow]=475,maxy[fow]=537,maxx[fow]=695;
                if(nowy>=475&&nowy<=495){
                    miny[fow]=495-(nowx-520);
                    minx[fow]=520+(495-nowy);
                }
                if(nowx>=530&&nowx<=620){
                    if(nowy==537&&fow==0){
                        move_ = 0;
                        return false;
                    }
                    if(fow==1){
                        if(nowy>=537&&nowy<=547){
                            minx[fow]=530+(nowy-537)*2;
                            maxy[fow]=537+(nowx-530)/2;
                        }
                    }
                }
            }
            else if(nowx>=540&&nowx<=695&&nowy<=547&&nowy>=475){
                minx[fow]=35,miny[fow]=475,maxy[fow]=537,maxx[fow]=695;
                if(nowy>=475&&nowy<=500){
                    maxx[fow]=695+(500-nowy);
                }
                if(nowx>=540&&nowx<=620){
                    if(nowy==537&&fow==0){
                        move_ = 0;
                        return false;
                    }
                    if(fow==1){
                        if(nowy>=537&&nowy<=547&&nowx>=530&&nowx<=550){
                            minx[fow]=530+(nowy-537)*2;
                            maxy[fow]=537+(nowx-530)/2;
                        }
                        else if(nowx>=550&&nowx<=600){
                            maxy[fow]=547;
                        }
                        else if(nowx>=600&&nowx<=620){
                            if(nowy>=537&&nowy<=547){
                                maxx[fow]=600+(547-nowy)*2;
                                maxy[fow]=547-(nowx-600)/2;
                            }
                        }
                    }
                }
            }
            else if(nowx>=695&&nowx<=720&&nowy>=475&&nowy<=500){
                minx[fow]=35,miny[fow]=475;
                maxy[fow]=500-(nowx-695);
                maxx[fow]=695+(495-nowy);
            }
            else if(nowx>=695&&nowx<=755&&nowy<=475&&nowy>=360){
                minx[fow]=400,miny[fow]=410,maxy[fow]=475,maxx[fow]=755;
                if(nowx>=695&&nowx<=720){
                    miny[fow]=410-(720-nowx);
                    maxy[fow]=475+(720-nowx);
                }
                if(nowy<475&&nowy>435) minx[fow]=695;
            }
            else if(nowx<=695&&nowx>=670&&nowy<=440&&nowy>=380){
                minx[fow]=400,maxx[fow]=695;
                if(nowx>=670){
                    miny[fow]=380+(nowx-670);
                }
                else miny[fow]=380;
                maxy[fow]=440+(nowx-695);
            }
            else if(nowx>=645&&nowx<=670&&nowy<=416&&nowy>=355){
                minx[fow]=35,maxx[fow]=755,maxy[fow]=415;
                miny[fow]=380-(670-nowx);
            }
            else if(nowx>=385&&nowx<695&&nowy>=330&&nowy<=420){
                minx[fow] = 385,miny[fow] = 350,maxx[fow] = 695,maxy[fow] =415;
                if(nowx>=490&&nowx<=580){
                    if(nowy==415){
                        move_ = 0;
                        return false;
                    }
                }
            }
            else if(nowx>=345&&nowx<=385&&nowy>=330&&nowy<=420){
                maxx[fow] = 695,maxy[fow] =415;
                maxy[fow] = 415-(385-nowx);
                minx[fow] = 385-(415-nowy);
                if(nowx<=385&&nowx>=365){
                    miny[fow]=330+(nowx-365);
                    maxx[fow]=365+(nowy-330);
                }
                else miny[fow]=330;
            }
            else if(nowx>=98&&nowx<385&&nowy>=330&&nowy<=380){
                minx[fow] = 97,miny[fow] = 330,maxx[fow] = 385,maxy[fow] =375;
            }
            else if(nowx>=35&&nowx<=98&&nowy>=240&&nowy<=380){
                minx[fow] = 35,miny[fow] = 250,maxx[fow] = 400,maxy[fow] =375;
                if(nowy<330&&nowy>275){
                    maxx[fow]=98;
                }
            }
            else if(nowx>=98&&nowx<=405&&nowy>=240&&nowy<=300){
                minx[fow] = 98,miny[fow] = 250,maxx[fow] = 420,maxy[fow] =275;
            }
            else if(nowx>=405&&nowx<=425&&nowy>=240&&nowy<=295){
                maxx[fow]=755,miny[fow]=250,minx[fow]=35,maxy[fow]=275;
                if(nowy>=275&&nowy<=295){
                    minx[fow]=405+(nowy-275);
                    maxy[fow]=275+(nowx-405);
                }
            }
            else if(nowx>=425&&nowx<560&&nowy>=240&&nowy<=300){
                minx[fow] = 415,miny[fow] = 250,maxx[fow] = 692,maxy[fow] =295;
            }
            else if(nowx>=560&&nowx<=580&&nowy>=250&&nowy<=300){
                minx[fow] = 35,maxx[fow]=600,maxy[fow]=295;
                if(nowy>=250&&nowy<=270){
                    miny[fow]=250+(nowx-560);
                }
            }
            else if(nowx>=580&&nowx<=700&&nowy<=295&&nowy>=270){
                minx[fow]=35,maxx[fow]=755,maxy[fow]=295,miny[fow]=270;
            }
            else if(nowx>=700&&nowx<=755&&nowy<=295&&nowy>=155){
                minx[fow]=35,maxx[fow]=755,miny[fow]=155,maxy[fow]=295;
                if(nowy<=270&&nowy>=195){
                    minx[fow]=700;
                }
            }
            else if(nowx>=570&&nowx<=700&&nowy>=150&&nowy<=200){
                minx[fow] = 535,miny[fow] = 155,maxx[fow] = 755,maxy[fow] =195;
            }
            else if(nowx>=530&&nowx<=570&&nowy>=150&&nowy<=200){
                minx[fow] = 520,miny[fow] = 150,maxx[fow] = 600,maxy[fow]=195;
                if(nowy>=155&&nowy<=195){
                    minx[fow]=530+(nowy-155);
                    maxy[fow]=195-(570-nowx);
                }
            }
            else if(nowx>372&&nowx<530&&nowy>=150&&nowy<=160){
                minx[fow] = 372,miny[fow] = 155,maxx[fow] = 532,maxy[fow] = 155;
            }
            else if(nowx>=340&&nowx<=372&&nowy>=150&&nowy<=200){
                minx[fow] = 340,miny[fow] = 155,maxx[fow] = 372,maxy[fow] = 195;
                if(nowy==155){
                    maxx[fow]=400;
                }
                if(nowy==195){
                    minx[fow]=35;
                }
            }
            else if(nowx>215&&nowx<340&&nowy>=195&&nowy<=200){
                minx[fow] = 200,miny[fow] = 190,maxx[fow] = 345,maxy[fow] = 195;
            }
            else if(nowx>=195&&nowx<=215&&nowy<=195&&nowy>=110){
                minx[fow] = 170,miny[fow] = 110,maxx[fow] =300,maxy[fow] = 195;
                if(nowy<190&&nowy>=110){
                    maxx[fow]=215;
                }
                if(nowy>=110&&nowy<=130){
                    miny[fow]=110+(nowx-195);
                    maxx[fow]=195+(nowy-110);
                }
            }
            else if(nowx>=170&&nowx<195&&nowy<=195&&nowy>=110){
                minx[fow] = 170,miny[fow] = 110,maxx[fow] =300,maxy[fow] = 195;
                if(nowy>=110&&nowy<=160){
                    minx[fow]=135;
                }
            }
            else if(nowx>=135&&nowx<180&&nowy>=32&&nowy<=160){
                minx[fow] = 135,miny[fow] = 35,maxx[fow] =185,maxy[fow] = 160;
                if(nowy>=32&&nowy<=105){
                    minx[fow]=35;
                }
            }
            else if(nowx>=35&&nowx<=135&&nowy>=32&&nowy<=105)
            {
                 minx[fow]=35,miny[fow]=35,maxy[fow]=115,maxx[fow]=140;
            }
            else if(nowx>=180&&nowx<=200&&nowy>=32&&nowy<=75){
                minx[fow]=35,maxx[fow]=210,miny[fow]=35;
                if(nowy>=55&&nowy<=75){
                    maxy[fow]=75-(nowx-180);
                    maxx[fow]=180+(75-nowy);
                }
            }
            else if(nowx>=200&&nowx<=250&&nowy>=32&&nowy<=55){
                minx[fow] = 180,miny[fow] = 35,maxx[fow] =260,maxy[fow] = 55;
            }
            else if(nowx>=250&&nowx<=270&&nowy>=32&&nowy<=75){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=300,maxy[fow]=75;
                if(nowy>=55&&nowy<=75){
                    minx[fow]=250+(nowy-55);
                    maxy[fow]=55+(nowx-250);
                }
            }
            else if(nowx>=270&&nowx<=290&&nowy>=32&&nowy<=75){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=300,maxy[fow]=75;
            }
            else if(nowx>=290&&nowx<=310&&nowy>=32&&nowy<=95){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=320,maxy[fow]=95;
                if(nowy>=75&&nowy<=95){
                    minx[fow]=290+(nowy-75);
                    maxy[fow]=75+(nowx-290);
                }
            }
            else if(nowx>=310&&nowx<=520&&nowy>=32&&nowy<=95){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=530,maxy[fow]=95;
            }
            else if(nowx>=520&&nowx<=540&&nowy>=32&&nowy<=95){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=550,maxy[fow]=95;
                if(nowy>=75&&nowy<=95){
                    maxx[fow]=520+(95-nowy);
                    maxy[fow]=95-(nowx-520);
                }
            }
            else if(nowx>=540&&nowx<=605&&nowy>=32&&nowy<=75){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=640,maxy[fow]=75;
            }
            else if(nowx>=605&&nowx<=625&&nowy>=32&&nowy<=95){
                minx[fow]= 200,miny[fow]=35,maxx[fow]=755,maxy[fow]=95;
                if(nowy>=75&&nowy<=95){
                    minx[fow]=605+(nowy-75);
                    maxy[fow]=75+(nowx-605);
                }
            }
            else if(nowx>=625&&nowx<=755&&nowy>=32&&nowy<=95){
                minx[fow]=500,miny[fow]=35,maxy[fow]=95,maxx[fow]=755;
            }
            if(x[0]>=630&&x[0]<=690&&y[0]>=75&&y[0]<=98&&x[1]>=690&&x[1]<=750&&y[1]>=75&&y[1]<=98)
            {
                move_ = 0;
                if(rednumber==4&&bluenumber==4)
                    emit this->winend1();
                else
                    emit this->winend2();

            }
        //吃钻石
        if(nowx>=390&&nowx<=430&&nowy>=506&&nowy<=530&&fow==0){
                    if(redget[0]==false){
                    ui->red1->setVisible(false);
                    redget[0] = true;
                    rednumber++;
                    }
                }
                if(nowx>=130&&nowx<=170&&nowy>=250&&nowy<=280&&fow==0){
                    if(redget[1]==false){
                    ui->red2->setVisible(false);
                    redget[1] = true;
                    rednumber++;
                    }
                }
                if(nowx>=210&&nowx<=230&&nowy>=32&&nowy<=62&&fow==0){
                    if(redget[2]==false){
                    ui->red3->setVisible(false);
                    redget[2] = true;
                    rednumber++;
                    }
                }
                if(nowx>=340&&nowx<=380&&nowy>=50&&nowy<=98&&fow==0){
                    if(redget[3]==false){
                    ui->red4->setVisible(false);
                    redget[3] = true;
                    rednumber++;
                    }
                }
        if(nowx>=560&&nowx<=600&&nowy>=506&&nowy<=530&&fow==1){
            if(blueget[0]==false){
            ui->blue1->setVisible(false);
            blueget[0] = true;
            bluenumber++;
            }
        }
        if(nowx>=480&&nowx<=520&&nowy>=270&&nowy<=295&&fow==1){
            if(blueget[1]==false){
            ui->blue2->setVisible(false);
            blueget[1] = true;
            bluenumber++;
            }
        }
        if(nowx>=60&&nowx<=100&&nowy>=80&&nowy<=120&&fow==1){
            if(blueget[2]==false){
            ui->blue3->setVisible(false);
            blueget[2] = true;
            bluenumber++;
            }
        }
        if(nowx>=430&&nowx<=470&&nowy>=50&&nowy<=98&&fow==1){
            if(blueget[3]==false){
            ui->blue4->setVisible(false);
            blueget[3] = true;
            bluenumber++;
            }
        }
        return true;
}


void game::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1){
        int modx[2]={0},mody[2]={0};
        if(GetAsyncKeyState('A')&0x8000){
            modx[1]--;
                }
                if(GetAsyncKeyState('D')&0x8000){
                    modx[1]++;
                }
                if(GetAsyncKeyState('W')&0x8000){
                    mody[1]++;
                }
                if(GetAsyncKeyState(VK_LEFT)&0x8000){
                    modx[0]--;
                }
                if(GetAsyncKeyState(VK_RIGHT)&0x8000){
                    modx[0]++;
                }
                if(GetAsyncKeyState(VK_UP)&0x8000){
                    mody[0]++;
                }
                for(int i=0;i<=1;i++){
                    if(modx[i]>0) {vx[i]+=0.1; if(vx[i]>1.5) vx[i]=1.5;}
                    else if(modx[i]<0) {vx[i]-=0.1; if(vx[i]<-1.5) vx[i]=-1.5;}
                    else vx[i]=0;
                    if(mody[i]>0){
                        if(vy[i]!=0);
                        else if(vy[i]==0) vy[i]=2.5;
                    }
                    if(vy[i]==0&&y[i]==maxy[i]) ay[i]=0;
                    else ay[i]=0.03;
                    vy[i]-=ay[i];
                    if(vy[i]<=-2.5){
                        vy[i]=0;
                    }
                    if(y[i]==maxy[i]&&x[i]==maxx[i]&&mody[i]==0){
                        vy[i]=vx[i];
                    }
                    x[i]+=vx[i]*move_;
                    y[i]-=vy[i]*move_;
                }
                bool lose_judge1 = getMaxAndMin(x[0],y[0],0);
                bool lose_judge2 = getMaxAndMin(x[1],y[1],1);
                if(lose_judge1==false||lose_judge2==false){
                    emit this->loseend1();
                }
                for(int i=0;i<=1;i++){
                    if(this->x[i]<=minx[i]) {this->x[i]=minx[i]; this->vx[i]=0;}
                    else if(this->x[i]>=maxx[i]) {this->x[i]=maxx[i]; this->vx[i]=0;}
                    if(this->y[i]>=maxy[i]) {this->y[i]=maxy[i]; this->vy[i]=0; this->ay[i]=0;}
                    else if(this->y[i]<=miny[i]) {this->y[i]=miny[i]; if(vy[i]>0)this->vy[i]=-0.01;}
                }
                this->ui->fireman->move(x[0]-10,y[0]-5);
                this->ui->watergirl->move(x[1]-9,y[1]-8);
    }
}
void game::reset()
{
    x[0]=55,y[0]=537,x[1]=55,y[1]=445;
    ay[0]=0,ay[1]=0,vy[0]=0,vy[1]=0,vx[0]=0,vx[1]=0;
    minx[0]=35,miny[0]=510,maxy[0]=537,maxx[0]=765;
    minx[1]=35,miny[1]=430,maxy[1]=452,maxx[1]=765;
    ui->red1->setVisible(true);
    ui->red2->setVisible(true);
    ui->red3->setVisible(true);
    ui->red4->setVisible(true);
    ui->blue1->setVisible(true);
    ui->blue2->setVisible(true);
    ui->blue3->setVisible(true);
    ui->blue4->setVisible(true);
    rednumber = 0;
    bluenumber = 0;
    memset(redget,false,sizeof (redget));
    memset(blueget,false,sizeof (blueget));
    this->ui->watergirl->move(55,435);
    move_ = 1;
}
