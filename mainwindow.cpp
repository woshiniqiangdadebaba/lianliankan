#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLayout>
#include<QWidget>
#include"map.h"
#include"help.h"
#include"option.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    help =new Help;
    map = new Map;
    option = new Option;   //建立指针
    connect(ui->helpText,SIGNAL(clicked()),help,SLOT(exec()));
    connect(ui->help_text,SIGNAL(clicked()),help,SLOT(exec()));
    connect(ui->gameOver,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->over,SIGNAL(clicked()),this,SLOT(close()));
    connect(map,SIGNAL(finishOption()),this,SLOT(overOption()));
    connect(option,SIGNAL(newOption(int,int)),map,SLOT(newOption(int,int)));
    connect(ui->restart,SIGNAL(clicked()),this,SLOT(restart()));
    ui->restart->setVisible(false);
    ui->pause->setVisible(false);
    ui->helpText->setVisible(false);
    ui->hint->setVisible(false);
    ui->choose->setEnabled(false);
    ui->over->setVisible(false);
    ui->start->setEnabled(false);
    ui->fail->setVisible(false);
    ui->win->setVisible(false);
    ui->error->setVisible(false);
    create_action();
    while(1)
  {
      btn[0]=ui->btn11;
      btn[1]=ui->btn12;
      btn[2]=ui->btn13;
      btn[3]=ui->btn14;
      btn[4]=ui->btn15;
      btn[5]=ui->btn16;
      btn[6]=ui->btn17;
      btn[7]=ui->btn18;
      btn[8]=ui->btn19;
      btn[9]=ui->btn1_10;

      btn[10]=ui->btn21;
      btn[11]=ui->btn22;
      btn[12]=ui->btn23;
      btn[13]=ui->btn24;
      btn[14]=ui->btn25;
      btn[15]=ui->btn26;
      btn[16]=ui->btn27;
      btn[17]=ui->btn28;
      btn[18]=ui->btn29;
      btn[19]=ui->btn2_10;

      btn[20]=ui->btn31;
      btn[21]=ui->btn32;
      btn[22]=ui->btn33;
      btn[23]=ui->btn34;
      btn[24]=ui->btn35;
      btn[25]=ui->btn36;
      btn[26]=ui->btn37;
      btn[27]=ui->btn38;
      btn[28]=ui->btn39;
      btn[29]=ui->btn3_10;

      btn[30]=ui->btn41;
      btn[31]=ui->btn42;
      btn[32]=ui->btn43;
      btn[33]=ui->btn44;
      btn[34]=ui->btn45;
      btn[35]=ui->btn46;
      btn[36]=ui->btn47;
      btn[37]=ui->btn48;
      btn[38]=ui->btn49;
      btn[39]=ui->btn4_10;

      btn[40]=ui->btn51;
      btn[41]=ui->btn52;
      btn[42]=ui->btn53;
      btn[43]=ui->btn54;
      btn[44]=ui->btn55;
      btn[45]=ui->btn56;
      btn[46]=ui->btn57;
      btn[47]=ui->btn58;
      btn[48]=ui->btn59;
      btn[49]=ui->btn5_10;

      btn[50]=ui->btn61;
      btn[51]=ui->btn62;
      btn[52]=ui->btn63;
      btn[53]=ui->btn64;
      btn[54]=ui->btn65;
      btn[55]=ui->btn66;
      btn[56]=ui->btn67;
      btn[57]=ui->btn68;
      btn[58]=ui->btn69;
      btn[59]=ui->btn6_10;

      btn[60]=ui->btn71;
      btn[61]=ui->btn72;
      btn[62]=ui->btn73;
      btn[63]=ui->btn74;
      btn[64]=ui->btn75;
      btn[65]=ui->btn76;
      btn[66]=ui->btn77;
      btn[67]=ui->btn78;
      btn[68]=ui->btn79;
      btn[69]=ui->btn7_10;

      btn[70]=ui->btn81;
      btn[71]=ui->btn82;
      btn[72]=ui->btn83;
      btn[73]=ui->btn84;
      btn[74]=ui->btn85;
      btn[75]=ui->btn86;
      btn[76]=ui->btn87;
      btn[77]=ui->btn88;
      btn[78]=ui->btn89;
      btn[79]=ui->btn8_10;

      btn[80]=ui->btn91;
      btn[81]=ui->btn92;
      btn[82]=ui->btn93;
      btn[83]=ui->btn94;
      btn[84]=ui->btn95;
      btn[85]=ui->btn96;
      btn[86]=ui->btn97;
      btn[87]=ui->btn98;
      btn[88]=ui->btn99;
      btn[89]=ui->btn9_10;

      btn[90]=ui->btn10_1;
      btn[91]=ui->btn10_2;
      btn[92]=ui->btn10_3;
      btn[93]=ui->btn10_4;
      btn[94]=ui->btn10_5;
      btn[95]=ui->btn10_6;
      btn[96]=ui->btn10_7;
      btn[97]=ui->btn10_8;
      btn[98]=ui->btn10_9;
      btn[99]=ui->btn10_10;
      break;
   }
    for(int i=0;i<100;i++)
        btn[i]->setVisible(0);
    for(int i=0;i<100;i++)
    {
        connect(btn[i],SIGNAL(clicked(bool)),this,SLOT(call_judge()));
    }
    connect(ui->hint,SIGNAL(clicked(bool)),this,SLOT(call_hint()));

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    ui->timeCount->setRange(0,100);
    ui->timeCount->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::create_action()
{

    connect(ui->begin,SIGNAL(clicked(bool)),option,SLOT(changeOption()));
    connect(ui->begin,SIGNAL(clicked(bool)),this,SLOT(call_newgame()));
    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(goStart()));
    connect(ui->pause,SIGNAL(clicked(bool)),this,SLOT(goStop()));
    connect(ui->choose,SIGNAL(clicked(bool)),option,SLOT(exec()));

}

//开始
void MainWindow::goStart()
{
    for(int i=0;i<100;i++)
        btn[i]->setEnabled(1);
    ui->restart->setEnabled(true);
    ui->hint->setEnabled(1);
    ui->start->setEnabled(0);
    ui->pause->setEnabled(1);
    ui->hint->setVisible(true);
    ui->over->setVisible(true);
    ui->helpText->setVisible(true);
    ui->pause->setVisible(true);
    ui->choose->setVisible(false);
    ui->restart->setVisible(true);
    if(option->getlevels()==1)
    {
        timer->start(3000);
    }
    else if(option->getlevels()==2)
    {
        timer->start(2000);
    }
    else if(option->getlevels()==3)
    {
        timer->start(1500);
    }
}
//暂停
void MainWindow::goStop()
{
    for(int i=0;i<100;i++)
        btn[i]->setEnabled(0);
    ui->hint->setEnabled(0);
    ui->start->setEnabled(1);
    ui->pause->setEnabled(0);

    timer->stop();
}
//选择结束
void MainWindow::overOption()
{
    ui->start->setEnabled(1);
    map->newGame(btn);  //建立新游戏
}

//新建
void MainWindow::call_newgame()
{
    ui->choose->setEnabled(true);
    ui->start->setEnabled(true);
    ui->pause->setEnabled(0);
    ui->begin->setVisible(0);
    ui->help_text->setVisible(0);
    ui->restart->setVisible(false);
    ui->gameOver->setVisible(0);
    for(int i=0;i<100;i++)
    {
        btn[i]->setEnabled(0);
        btn[i]->setVisible(1);
    }

    ui->hint->setVisible(false);
    ui->hint->setEnabled(0);

    map->newGame(btn);

    timer->stop();
    timing=100;
    ui->timeCount->setVisible(1);
    ui->timeCount->setValue(timing);
}

//判断消去
void MainWindow::call_judge()
{
    int wl;
    map->judge(btn);
    wl=map->win_loss(btn);
    if(wl)
    {
        ui->win->setVisible(true);
        ui->hint->setVisible(0);
        timer->stop();
        ui->pause->setEnabled(0);
        ui->timeCount->setVisible(0);
    }
}

//提示
void MainWindow::call_hint()
{
    int wl;
    int h=map->hint(btn);
    if(h==0)
    {
        map->generate(map->getType(),btn);

    }
    wl=map->win_loss(btn);
    if(wl&&h)
    {
        ui->win->setVisible(true);
        ui->hint->setVisible(0);
        timer->stop();
        ui->pause->setEnabled(0);
        ui->timeCount->setVisible(0);
    }
}

void MainWindow::restart()
{
    call_newgame();
    ui->fail->setVisible(false);
    ui->win->setVisible(false);
    ui->restart->setEnabled(false);
    ui->restart->setVisible(true);
    ui->choose->setVisible(true);
    ui->hint->setVisible(true);
    ui->error->setVisible(false);

}

//时间条
void MainWindow::timerUpDate()
{
    timing--;
    ui->timeCount->setValue(timing);
    if(timing==0)
    {
        ui->fail->setVisible(true);
        for(int i=0;i<100;i++)
            btn[i]->setVisible(0);

        ui->hint->setVisible(0);
        ui->timeCount->setVisible(0);
        timer->stop();
        ui->pause->setEnabled(0);
    }
}
