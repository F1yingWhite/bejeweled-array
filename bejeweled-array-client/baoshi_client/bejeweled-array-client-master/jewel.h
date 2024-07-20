#ifndef JEWEL_H
#define JEWEL_H
#include<QString>
#include<QLabel>
#include<QDragEnterEvent>
#include<QMimeData>
#include<QDrag>
#include<QDebug>
#include<QMovie>
#include<QApplication>
#include<QPushButton>
//宝石类的声明
//这里改写为继承用法 gxc 获得 button 直接this调用即可
class Jewel : public QPushButton{
      Q_OBJECT
private:
    //QString color;
    int type;     //宝石的种类
    int x;        //当前宝石的x坐标
    int y;        //当前宝石的y坐标
    bool choosed; //是否背选中
    bool movieStart = false;
    QMovie* myMovie = new QMovie();
    QIcon * ico;
    bool isdongtu;



public:
    int where;
    //重写的时候默认使用button的构造器初始化 gxc
    Jewel(int x , int y , int type,int where ,QWidget *parent = nullptr);      //初始化宝石的坐标和对应的QLabel的生成以及图片的加载
    ~Jewel();                           //析构函数
    QPushButton* getbutton();                    //获取当前宝石的button
    int getX(){return x;}
    int getY(){return y;}
    void change_TeShu1();
    void change_TeShu2();
    void change_TeShu3();
    void changePos(Jewel *p){int x = p->getX(); int y = p->getY(); p->x = this->x; p->y = this->y; this->x = x; this->y = y;}
    void changePicture(int x);
    void bomb();
    void bomb1();
signals:
    void jewPosSignal(int x,int y);

private slots:
    void sendPosInfo_onclicked();
    void setButtonIcon(int frame)
    {
        if(isdongtu){
        this->setIcon(QIcon(myMovie->currentPixmap()));
        }else{
            QPixmap *pic = new QPixmap();
            QString pic_path = ":/new/prefix1/media/media/"+QString::number(type)+".png";     //加载图片路径
            pic->load(pic_path);
            pic->scaled(63,63);
            QIcon buttonIcon(*pic);
            for(int i = 1;i<7;i++)
            this->setIcon(buttonIcon);
        }
    }



};

#endif // JEWEL_H


