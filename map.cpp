#include<QBoxLayout>
#include<QPushButton>
#include"map.h"
#include"mainwindow.h"
#include<QWidget>
Map::Map(QWidget* parent):QDialog(parent)
{
    //默认为容易
    level = 1;
    type = 1;
    newOption(level,type);
}

int Map::getLevel()
{
    return level;
}

int Map::getType()
{
    return type;
}


void Map::newGame(QPushButton *btn[])
{
    init_ic(level);
    add_icon(type,btn);
}

void Map::newOption(int le, int ty)
{
    level = le;
    type = ty;
    emit finishOption();  //完成自定义
}

//初始化图片编号的数组并打乱
void Map::init_ic(int level)
{
    int k=0;

    //A组图片
    if(level==1) //简单
    {
        //
        for(int i=1;i<11;i++)
        {
            for(int j=0;j<4;j++)
            {
                ic[k++]=i;
            }
        }
        for(int i=11;i<=20;i++)
        {
            for(int j=0;j<6;j++)
            {
                ic[k++]=i;
            }
        }
    }
    else if(level==2)
    {
        for(int i=1;i<11;i++)
        {
            for(int j=0;j<4;j++)
            {
                ic[k++]=i;
            }
        }
        for(int i=11;i<=20;i++)
        {
            for(int j=0;j<6;j++)
            {
                ic[k++]=i;
            }
        }
    }
    else if(level==3)
    {
        for(int i=1;i<=25;i++)
        {
            for(int j=0;j<4;j++)
            {
                ic[k++]=i;
            }
        }
    }
    //交换
    srand((unsigned int)time(NULL));
    for(int i=0;i<200;i++)
    {
        int rand_num1=rand()%100;
        int rand_num2=rand()%100;

        int temp=ic[rand_num1];
        ic[rand_num1]=ic[rand_num2];
        ic[rand_num2]=temp;
    }
}

//初始化图片
void Map::add_icon(int type, QPushButton *button[])
{
    if(type==1)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/animal/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
    if(type==2)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/fruit/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
    if(type==3)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/vehicle/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
}

//判断能否连接
bool Map::is_linkable(QPushButton *button[], int r1, int c1, int r2, int c2)
{
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};

    Point st[10000];
    st[0].r=r1;
    st[0].c=c1;
    st[0].dir=-1;
    st[0].change=0;

    int dir,change;
    int left=0,right=1;

    while(left<right)
    {
        Point p=st[left];
        dir=p.dir;
        change=p.change;

        for(int i=0;i<4;i++)
        {
            int rr=p.r+dx[i], cc=p.c+dy[i];

            if(rr<-1||rr>10||cc<-1||cc>10)
                continue;
            if(i!=dir&&(change+1)>3)
                continue;

            if(rr==r2&&cc==c2)
                return true;

            if(rr>=0&&rr<=9&&cc>=0&&cc<=9&&button[10*rr+cc]->isVisible())
                continue;

            Point now;
            now.r=rr;
            now.c=cc;
            now.dir=i;

            if(i==dir)
                now.change=change;
            else
                now.change=change+1;
            st[right++]=now;
        }
        left++;
    }
    return false;
}

//判断能否消去
void Map::judge(QPushButton *button[])
{
    int cnt=0,at[2];
    for(int i=0;i<100;i++)
    {
        if(button[i]->isChecked())
            at[cnt++]=i;
    }
    if(cnt==2)
    {
        button[at[0]]->setChecked(0);
        button[at[1]]->setChecked(0);

        if(ic[at[0]]==ic[at[1]])
        {
            int r1=at[0]/10,c1=at[0]%10;
            int r2=at[1]/10,c2=at[1]%10;

            if(is_linkable(button,r1,c1,r2,c2))
            {
                button[at[0]]->setVisible(0);
                button[at[1]]->setVisible(0);
            }
        }
    }
    return;
}

//提示
bool Map::hint(QPushButton *button[])
{
    for(int i=0;i<100;i++)
    {
        if(button[i]->isVisible())
        {
            for(int j=i+1;j<100;j++)
            {
                if(button[j]->isVisible()&&ic[i]==ic[j]&&is_linkable(button,i/10,i%10,j/10,j%10))
                 {
                    button[i]->setVisible(0);
                    button[j]->setVisible(0);
                    return 1;
                  }
            }
        }
    }
    //提示不出
    return 0;
}

//重新生成

void Map::generate(int type, QPushButton *button[])
{
    //交换
    srand((unsigned int)time(NULL));
    for(int i=0;i<200;i++)
    {
        int rand_num1=rand()%100;
        int rand_num2=rand()%100;

        if(button[rand_num1]->isVisible()&&button[rand_num2]->isVisible()){
            int temp=ic[rand_num1];
            ic[rand_num1]=ic[rand_num2];
            ic[rand_num2]=temp;
        }
    }
    if(type==1)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/animal/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
    if(type==2)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/fruit/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
    if(type==3)
    {
        for(int i=0;i<100;i++)
        {
            button[i]->setIcon(QIcon(":/vehicle/"+QString::number(ic[i])));
            button[i]->setIconSize(QSize(40,40));
        }
    }
}
//判断输赢
bool Map::win_loss(QPushButton *button[])
{
    int i;
    for(i=0;i<100;i++)
        if(button[i]->isVisible())
            return 0;
    return 1;
}
