#include "jewel.h"
Jewel::Jewel(int x, int y, int type , QWidget *parent):QPushButton(parent)
{
    this->x = x;
    this->y = y;
    this->type = type;
    this->setCheckable(true);
    this->setGeometry(85*(x+1)+232,85*(y+1)+40,65,71);//这里的坐标可能需要改为数组下标然后使用计算函数得到坐标 xyh
    QPixmap *pic = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/"+QString::number(type)+".png";     //加载图片路径    
    pic->load(pic_path);    
    pic->scaled(65,71);
    QIcon buttonIcon(*pic);
    this->setIcon(buttonIcon);
    this->setIconSize(pic->rect().size());
    this->setFixedSize(pic->rect().size());
    this->setStyleSheet("QPushButton{border:none;background:transparent;}"); //将button设置为透明

    //链接信号槽 gxc
     connect(this,SIGNAL(clicked(bool)),this,SLOT(sendPosInfo_onclicked()));

     //直接在这里调样式 我还没找到啥好看的 style sheet
     this->setStyleSheet(
        "QPushButton:hover {border:none;background:transparent;border:2px solid #000000;}"  // 鼠标悬浮时的色彩
        "QPushButton:pressed{border:none;background:transparent;border:2px solid #000000;}");  // 鼠标按下的色彩

}

void Jewel::sendPosInfo_onclicked(){
    //这个x 和 y还需要处理
    //todo
    emit jewPosSignal(x,y);
}

void Jewel::changePicture(int x){
    QPixmap *pic = new QPixmap();
    QString pic_path = ":/new/prefix1/media/media/"+QString::number(x)+".png";     //加载图片路径
    pic->load(pic_path);
    pic->scaled(65,71);
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

