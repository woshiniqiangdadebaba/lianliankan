#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"map.h"
#include"help.h"
#include"option.h"
#include <QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QPushButton>
#include<QTimer>
#include<QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    QTimer *timer=new QTimer(this);
    int timing=100;


    Ui::MainWindow *ui;
    Map* map;
    Option* option;
    Help* help;
    QPushButton *btn[100];
    void create_action();
private slots:
    void goStop();
    void goStart();

    void call_newgame();
    void call_judge();
    void call_hint();

    void timerUpDate();
public slots:
    void overOption();
};

#endif // MAINWINDOW_H
