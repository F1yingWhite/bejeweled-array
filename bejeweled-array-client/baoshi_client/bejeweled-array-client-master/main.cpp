#include "mainwindow.h"
#include <form.h>
#include <QApplication>
#include <menu.h>
#include <play.h>
//gxc 加入战场
//我是一个一个

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Play play;
    menu menu1;
    Form form;
    w.show();
//    menu1.show();


    QObject::connect(&w,SIGNAL(JumptoWork()),&menu1,SLOT(OpenToWork()));
    QObject::connect(&menu1,SIGNAL(start()),&play,SLOT(OpenToWork1()));
    QObject::connect(&menu1,SIGNAL(TwoPlay()),&form,SLOT(OpenToWork2()));
    return a.exec();
}


