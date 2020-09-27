#include"help.h"
#include<QBoxLayout>

Help::Help(QWidget* parent):QDialog(parent)
{

    texts = new QTextEdit;
    texts->setFixedSize(700,520);
    QString  str(""
                 "");
    QString str0("游戏规则:");
    QString str1("点击两张图片，若这两张图片可以用3条线段相连，则可以消除这两张图片！");
    QString str2("在规定时间内消除所有的图片即可获得胜利，否则则游戏失败！");
    QString str3("游戏难度选择:");
    QString str4("默认难度为 普通");
    QString str5("简单：10组有4个相同的图片，10组有6个相同的图片，时间限制为300s");
    QString str6("普通：10组有4个相同的图片，10组有6个相同图片，时间限制为200s");
    QString str7("困难：25组有4个相同的图片，时间限制为150s");
    QString str8("提示:");
    QString str9("当你发现找不出能够相连的两张图片时，点击消去一组可以打乱图片位置。当然你也可以通过不断点击消去按钮来降低游戏难度。");
    QString str10("最后祝你玩的开心！");

    texts->append(str0);
    texts->append(str1);
    texts->append(str2);
    texts->append(str);
    texts->append(str3);
    texts->append(str4);
    texts->append(str5);
    texts->append(str6);
    texts->append(str7);
    texts->append(str);
    texts->append(str8);
    texts->append(str9);
    texts->append(str10);
    texts->setReadOnly(true);
    texts->setFont(QFont("YouYuan",20));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(texts);
    setLayout(layout);

    layout->setSizeConstraint(QLayout::SetFixedSize);
    setWindowTitle("游戏帮助");
}
