#ifndef MAP_H
#define MAP_H

#include<QDialog>
#include <cstdlib>
#include <ctime>
#include <QPushButton>

struct Point
{
    int r,c;
    int dir;
    int change;
};

class Map:public QDialog
{
    Q_OBJECT
private:
    int level;
    int type;
    int ic[100];

public:
    Map(QWidget* parent = 0);//控件不是任何类的子控件
    int getLevel();
    int getType();
    void init_ic(int level);
    void add_icon(int type, QPushButton *button[]);

    void newGame(QPushButton *bt[]);
    void generate(int type, QPushButton *button[]);

    bool is_linkable(QPushButton *button[], int, int, int, int);
    void judge(QPushButton *button[]);
    bool hint(QPushButton *button[]);

    bool win_loss(QPushButton *button[]);

public slots:
    void newOption(int, int);

signals:
    void finishOption();
};

#endif // MAP_H
