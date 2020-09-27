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
    QRadioButton* fruit_button;
    QRadioButton* vehicle_button;

    QPushButton* ok_button;

public:
    Option(QWidget* parent = 0);
    int getlevels();

public slots:
    void changeOption();

signals:
    void newOption(int,int);

};

#endif // OPTION_H
