#ifndef ANIMATION_H
#define ANIMATION_H
#include<QPropertyAnimation>
#include<QPushButton>
#include<form.h>
#include<QGraphicsView>
class Animation{
public:
 Animation(QPushButton*);
 ~Animation();
 void start();
 void settime(int time){this->time = time;}
 void setValue(QPoint, QPoint);
 QPropertyAnimation* getObj();

private:
 QPropertyAnimation *anima;
 int x;
 int y;
 int time;
};

#endif // ANIMATION_H
