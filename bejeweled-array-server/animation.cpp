#include"animation.h"
Animation::Animation(QPushButton *t)
{
    anima = new QPropertyAnimation(t,"pos");
    time = 500;
}

Animation::~Animation()
{

}

void Animation::setValue(QPoint s, QPoint e)
{
    anima->setStartValue(s);
    anima->setEndValue(e);
    anima->setDuration(time);
    anima->setEasingCurve(QEasingCurve::InOutCubic); //平滑曲线
}

void Animation::start()
{
    anima->start();
}

QPropertyAnimation* Animation::getObj()
{
    return anima;
}
