#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*w.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap("qrc:/new/prefix1/b1.jpg");
    palette.setBrush(QPalette::window,QBrush(pixmap));
    w.setPalette(palette);*/
    w.show();

    return a.exec();
}
