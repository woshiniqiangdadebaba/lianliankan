#include<option.h>
#include<QBoxLayout>

//游戏自定义按键设置
Option::Option(QWidget* parent):QDialog(parent)
{
    levels=1;
    types=1;

    //难度选择
    easy_button = new QRadioButton("简单");

    easy_button->setChecked(1);
    mid_button = new QRadioButton("一般");

    hard_button = new QRadioButton("困难");

    level_box = new QGroupBox("游戏难度");

    //level 垂直排布
    QVBoxLayout* level_layout = new QVBoxLayout;
    level_layout->addWidget(easy_button);
    level_layout->addWidget(mid_button);
    level_layout->addWidget(hard_button);
    level_box->setLayout(level_layout);


    //图片类型选择
    animal_button = new QRadioButton("动物");
    animal_button->setChecked(1);//默认为动物

    fruit_button = new QRadioButton("果蔬");
    vehicle_button = new QRadioButton("交通工具");
    type_box = new QGroupBox("图片类型");

    //type 垂直排布
    QVBoxLayout* type_layout = new QVBoxLayout;
    type_layout->addWidget(animal_button);
    type_layout->addWidget(fruit_button);
    type_layout->addWidget(vehicle_button);
    type_box->setLayout(type_layout);

    //确定键 水平排布
    ok_button = new QPushButton("确定");

    QHBoxLayout* button_layout = new QHBoxLayout;
    button_layout->addStretch();  //分隔
    button_layout->addWidget(ok_button);

    connect(ok_button,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ok_button,SIGNAL(clicked()),this,SLOT(changeOption()));


    //整体布局
    QHBoxLayout* option_layout = new QHBoxLayout;
    option_layout->addWidget(level_box);
    option_layout->addWidget(type_box);

    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->addLayout(option_layout);
    main_layout->addLayout(button_layout);
    setLayout(main_layout);

    setWindowTitle("游戏选项");
    setFont(QFont("YouYuan",20));
    main_layout->setSizeConstraint(QLayout::SetFixedSize);  //根据内部控件自动固定大小
}


// 难度 图片设置
void Option::changeOption()
{
    if(easy_button->isChecked())
     levels = 1;  // 4*10 + 6*10 300s
    if(mid_button->isChecked())
     levels = 2;  // 4*10 + 6*10 200s
    if(hard_button->isChecked())
     levels = 3;  // 4x20 100s

    if(animal_button->isChecked())
     types = 1;  //life
    if(fruit_button->isChecked())
     types = 2;  //animal
    if(vehicle_button->isChecked())
     types = 3; //dota

    emit newOption(levels,types);
}

int Option::getlevels()
{
    return levels;
}

