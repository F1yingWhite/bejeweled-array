#include "jewel.h"
#include <QTime>
Jewel::Jewel(int x, int y, int type,int where , QWidget *parent):QPushButton(parent)
{
    this->x = x;
    this->where = where;
    this->y = y;
    this->type = type;
    this->setCheckable(true);
    if(where == 1){
        this->setGeometry(67*(y+1)+175,67*(x+1)+36,61,61);//这里的坐标可能需要改为数组下标然后使用计算函数得到坐标 xyh
    }
    else{
        this->setGeometry(67*(y+1)+879,67*(x+1)+36,61,61);
    }
    QPixmap *pic = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/"+QString::number(type)+".png";     //加载图片路径    
    pic->load(pic_path);    
    pic->scaled(63,63);
    QIcon buttonIcon(*pic);
    this->setIcon(buttonIcon);
    this->setIconSize(pic->rect().size());
    this->setFixedSize(pic->rect().size());
    this->setStyleSheet("QPushButton{border:none;background:transparent;}"  //将button设置为透明
                        "QPushButton:hover {border:none;background:transparent;border:1.5px solid #66FFFF;}"
                        "QPushButton:pressed{border:none;background-color:rgb(204,204,204);border-style:inset;}");

    //链接信号槽 gxc
     connect(this,SIGNAL(clicked(bool)),this,SLOT(sendPosInfo_onclicked()));
     QPixmap pixmap;
         // 光标图片 需要注意注意图片的大小 不然会比较难看
     pixmap.load(":/new/prefix1/media/media/handCursor.png");
     QCursor cursor(pixmap);
     setCursor(cursor);
    change_TeShu1();
    change_TeShu1();
    isdongtu = false;



}

void Jewel::sendPosInfo_onclicked(){
    //这个x 和 y还需要处理
    //todo
    emit jewPosSignal(x,y);

}

void Jewel::changePicture(int x){
    if(x>10){
        type = x%10;
        int j = x/10;
        if(j == 1){
            this->change_TeShu1();
        }
        else if(j == 2){
            this->change_TeShu2();
        }
    }
    else if(x==8){
        this->change_TeShu3();
    }
    else{
//        myMovie->deleteLater();
//        myMovie->
//        disconnect(myMovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
//        if (myMovie->loopCount() != -1)
//            disconnect(myMovie,SIGNAL(finished()),myMovie,SLOT(start()));

        QPixmap *pic = new QPixmap();
        QString pic_path = ":/new/prefix1/media/media/"+QString::number(x)+".png";     //加载图片路径
        type = x;
        pic->load(pic_path);
        pic->scaled(63,63);
        QIcon buttonIcon(*pic);
        this->setIcon(buttonIcon);

        isdongtu = false;
    }
}

void Jewel::change_TeShu2(){
    disconnect(myMovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
        disconnect(myMovie,SIGNAL(finished()),myMovie,SLOT(start()));

    movieStart = true;
    isdongtu = true;
    QString gif_path = ":/new/prefix1/media/media/"+QString::number(type)+"a.gif";
    myMovie = new QMovie(gif_path);
    connect(myMovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
    if (myMovie->loopCount() != -1)
        connect(myMovie,SIGNAL(finished()),myMovie,SLOT(start()));
    myMovie->setBackgroundColor("transparent");
    myMovie->start();
}
void Jewel::change_TeShu3(){
    disconnect(myMovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
    disconnect(myMovie,SIGNAL(finished()),myMovie,SLOT(start()));

    movieStart = true;
    isdongtu = true;
    myMovie = new QMovie(":/new/prefix1/media/media/Magic.gif");
    connect(myMovie,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
    if (myMovie->loopCount() != -1)
        connect(myMovie,SIGNAL(finished()),myMovie,SLOT(start()));
    myMovie->setBackgroundColor("transparent");
    myMovie->start();
}
void Jewel::change_TeShu1(){
    QPixmap *pic = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/"+QString::number(type)+"b.png";     //加载图片路径
    pic->load(pic_path);
    pic->scaled(63,63);
    QIcon buttonIcon(*pic);
    this->setIcon(buttonIcon);
}


Jewel::~Jewel()
{
    delete(this);
}


QPushButton* Jewel::getbutton()
{
    return this;
}


void Jewel::bomb()
{
    QPixmap *pic = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/partc1.png";     //加载图片路径
    pic->load(pic_path);
    pic->scaled(63,63);
    QIcon buttonIcon(*pic);
    this->setIcon(buttonIcon);

    QTime time;
    time.start();
    while(time.elapsed() < 5){
        QCoreApplication::processEvents();
    }

    pic_path = ":/new/prefix1/media/media/partc2.png";
    pic->load(pic_path);
    pic->scaled(63,63);
    QIcon buttonIcon1(*pic);
    this->setIcon(buttonIcon1);
}

void Jewel::bomb1()
{
    QPixmap *pic
            = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/partc1.png";     //加载图片路径
    pic->load(pic_path);
    pic->scaled(63,63);
    QIcon buttonIcon(*pic);
    this->setIcon(buttonIcon);

    QTime time;
    time.start();
    while(time.elapsed() < 5){
        QCoreApplication::processEvents();
    }

    pic_path = ":/new/prefix1/media/media/partc2.png";
    pic->load(pic_path);
    pic->scaled(63,63);
    QIcon buttonIcon1(*pic);
    this->setIcon(buttonIcon1);

    QTime time_1;
    time_1.start();
    while(time_1.elapsed() < 5){
        QCoreApplication::processEvents();
    }

    /* pic_path = ":/new/prefix1/media/media/touming.png";
     pic->load(pic_path);
     pic->scaled(63,63);
     QIcon button(*pic);
     this->setIcon(button);*///刷新

    QTime time_2;
    time_2.start();
    while(time_2.elapsed() < 50){
        QCoreApplication::processEvents();
    }
}
