#ifndef OPTION_H
#define OPTION_H

#include<QDialog>
#include<QRadioButton>
#include<QGroupBox>
#include<QPushButton>
class Option:public QDialog
{
    Q_OBJECT
private:
    int levels;
    int types;

    QGroupBox* level_box;
    QRadioButton* easy_button;
    QRadioButton* mid_button;
    QRadioButton* hard_button;

    QGroupBox* type_box;
    QRadioButton* animal_button;
    QRadioButton* life_button;
    QRadioButton* dota_button;

    QPushButton* ok_button;

public:
    Option(QWidget* parent = 0);
    int getlevels();//得到默认或选择后的难度值

public slots:
    void changeOption();//槽函数，改变难度和图片类型

signals:
    void newOption(int,int);//信号函数，将改变后的难度与图片类型所对应的值传递给GameMap 类的对象

};

#endif // OPTION_H
