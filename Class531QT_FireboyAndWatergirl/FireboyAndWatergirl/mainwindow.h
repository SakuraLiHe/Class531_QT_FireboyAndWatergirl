#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"game.h"
#include"set.h"
#include"more.h"
#include"winend.h"
#include"loseend.h"
#include"winend2.h"
#include"shadewindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //画背景图
    void paintEvent(QPaintEvent*);

    game*gam=NULL;
    set*se=NULL;
    more*mo=NULL;
    winend*win=NULL;
    loseend*lose=NULL;
    winend2*win2=NULL;
    shadewindow*shade=NULL;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
