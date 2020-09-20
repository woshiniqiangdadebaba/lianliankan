#ifndef HELP_H
#define HELP_H

#include<QDialog>
#include<QTextEdit>
class Help:public QDialog
{
private:
    QTextEdit* texts;
public:
    Help(QWidget* parent = 0);//控件不是任何控件的子控件
};



#endif // HELP_H
