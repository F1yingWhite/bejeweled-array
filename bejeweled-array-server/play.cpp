#include "play.h"
#include "ui_play.h"
#include "QMessageBox"
#include "QTextCodec.h"
#include <QIcon>
#include <QDebug>
#include <QMovie>
#include <QString>
#include <QHBoxLayout>
#include <QMouseEvent>
#include<QSignalMapper>
#include <cstdlib>
#include <ctime>
#include"animation.h"
#include<QDir>
#include<QTime>
#include<QParallelAnimationGroup>
using namespace std;
QGraphicsScene *scene_3;

Play::Play(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::Play)
{
   this->setWindowTitle("宝石迷阵");
   this->setWindowIcon(QIcon(":/new/prefix1/ICON/13369429051CA2411D99F227A90D19CB9BE4EA10C2.jpg"));
   ui->setupUi(this);
   ui->timer->setStyleSheet("QLCDNumber{border:none;background:transparent;}");


//    ui->lineEdit_Ip->setText("127.0.0.1");
//    ui->pushButton_Listen->setText("OpenServer");

   //添加menu
   auto layout = new QHBoxLayout(this);
   QMenuBar *menubar = new QMenuBar(this);
   layout->setMenuBar(menubar);
   Qtime = new QAction(this);                    //比赛时间
   Qtime->setText("时间");
   connect(Qtime, SIGNAL(triggered()), this,SLOT(slot_set_time()));
   music_on = new QAction(this);
   music_on->setText("音乐开");
   connect(music_on, SIGNAL(triggered()), this,SLOT(slot_music_on()));
   music_off = new QAction(this);
   music_off->setText("音乐关");
   connect(music_off, SIGNAL(triggered()), this, SLOT(slot_music_off()));
   music_turn = new QAction(this);
   music_turn->setText("更换音乐");
   connect(music_turn, SIGNAL(triggered()), this, SLOT(slot_music_change()));
   hint = new QAction(this);
   hint->setText("详细信息");
   connect(hint, SIGNAL(triggered()), this, SLOT(slot_hint()));
   setting = new QMenu("设置");
   setting->addAction(music_on);
   setting->addAction(music_off);
   setting->addAction(music_turn);
   setting->addAction(Qtime);
   menubar->addMenu(setting);
   help = new QMenu("帮助");
   help->addAction(hint);
   menubar->addMenu(help);
   layout->addWidget(this);
   layout->addWidget(menubar);


   //测试己方宝石
   scene_3 = new QGraphicsScene(ui->graphicsView);
   scene_3->setSceneRect(0,67,830,620);
   ui->graphicsView->setScene(scene_3);




//    updateBaoshi(a1);
//        for(int i = 0; i <8; i++){
//            for(int j = 0; j < 8; j++){
//                jew[i][j] = new Jewel(i,j,a1[i][j],1);
//                scene_3->addWidget(jew[i][j]->getbutton());
//            }
//        }
//        if(xiaochu(a1)){

//            xialuo(a1);
////            updateBaoshi(a);
//            while(xiaochu(a1)!=0){
//                 xialuo(a1);
////                 updateBaoshi(a);
//            }
////            for(int i = 0;i<8;i++){
////                for(int j = 0; j<8;j++){
////                    jew[i][j]->changePicture(a[i][j]);
////                }
////            }
//        }
//        //绑定槽函数
//        for(int i = 0; i <8; i++){
//            for(int j = 0; j < 8; j++){

//            }
//        }
//        for(int i = 0;i<8;i++){
//            for(int j = 0; j<8;j++){
//                jew[i][j]->changePicture(a1[i][j]);
//            }
//        }

        playlist->addMedia(QUrl("qrc:/new/prefix1/music/3.mp3"));
        playlist->addMedia(QUrl("qrc:/new/prefix1/music/1.mp3"));
        playlist->addMedia(QUrl("qrc:/new/prefix1/music/2.mp3"));
        playlist->setCurrentIndex(0);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        player_backMusic1->setPlaylist(playlist);
    //初始化音乐
        player_match1->setMedia(QUrl("qrc:/new/prefix1/music/1.mp3"));
        player_match2->setMedia(QUrl("qrc:/new/prefix1/music/2.mp3"));
        player_match3->setMedia(QUrl("qrc:/new/prefix1/music/3.mp3"));
        player_delete1->setMedia(QUrl("qrc:/new/prefix1/music/unbelievable.mp3"));
        player_delete2->setMedia(QUrl("qrc:/new/prefix1/music/amazing.ogg"));
        player_delete3->setMedia(QUrl("qrc:/new/prefix1/music/excellent.ogg"));
        player_delete4->setMedia(QUrl("qrc:/new/prefix1/music/great.mp3"));
        player_match1->setMedia(QUrl("qrc:/new/prefix1/music/match.wav"));
        player_click->setMedia(QUrl("qrc:/new/prefix1/music/click.wav"));
        start_timi->setMedia(QUrl("qrc:/new/prefix1/music/start_timi.wav"));
        fail->setMedia(QUrl("qrc:/new/prefix1/music/fail.wav"));
        player_click->setVolume(30);
        player_backMusic1->setVolume(50);
        player_match1->setVolume(50);
        player_delete1->setVolume(70);
        player_deletes.append(player_delete1);
        player_deletes.append(player_delete2);
        player_deletes.append(player_delete3);
        player_deletes.append(player_delete4);
        cur_del_mic = 0;
        music_num = 3;
        cur_music =0;
    QPixmap pixmap;
        // 光标图片 需要注意注意图片的大小 不然会比较难看
    pixmap.load(":/new/prefix1/media/media/handCursor.png");
    pixmap = pixmap.scaled(QSize(50,50));
    QCursor cursor(pixmap);
    setCursor(cursor);

   //更新字体
   QFont font = ui->ziji->font();
   QString family = QApplication::applicationDirPath() + ":/new/prefix1/media/media/fuentelcd.ttf";
   font.setFamily(family);
   ui->ziji->setFont(font);//设置控件自定义字体

   fenshu = 0;
    ui->label_3->setText("时间限制:1分钟");
}

Play::~Play()
{
   delete ui;
}





void Play::change(int x,int y){
   QMediaPlayer* tmp= new QMediaPlayer();
   tmp->setMedia(QUrl("qrc:/new/prefix1/music/match2.wav"));
   tmp->setVolume(30);
   tmp->play();
   Jewel* btn = (Jewel*)sender();// 获取到了发送该信号按钮的指针
   if(btn->where == 1){
       if(selectX1 == -1){
           selectX1=btn->getX();
           selectY1=btn->getY();
           jew[selectX1][selectY1]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");//改变样式表
//            jew[selectX1][selectY1]->change_TeShu3();
//            jew[selectX1][selectY1]->myMovie->start();
/*                QMovie *movie = new QMovie(":/new/prefix1/media/media/1.gif");
//                label->setMovie(movie); // 1. 设置要显示的 GIF 动画图片
               movie->start();*/         // 2. 启动动画
//                label->show();
       }
       else if(selectX2 == -1){
           selectX2 = btn->getX();
           selectY2 = btn->getY();
           if((selectX1==selectX2-1&&selectY2==selectY1)||(selectX1==selectX2+1&&selectY2==selectY1)||(selectX1==selectX2&&selectY2-1==selectY1)||(selectX1==selectX2&&selectY2+1==selectY1)){
               jew[selectX2][selectY2]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");
               int temp = a1[selectX1][selectY1];
               a1[selectX1][selectY1] = a1[selectX2][selectY2];
               a1[selectX2][selectY2] = temp;//交换矩阵
               if(a1[selectX1][selectY1] == 8 && a1[selectX2][selectY2] != 8){
                   int f = a1[selectX2][selectY2]%10;
                   a1[selectX1][selectY1] = 0;
                   for(int i=0;i<8;i++){
                       for(int j=0;j<8;j++){
                           if(a1[i][j] == f) {a1[i][j] = 0;fenshu++;}
                       }
                   }
                   ui->ziji->display(fenshu);
                   int i = 0;

                   QMediaPlayer* tmp = new QMediaPlayer();
                   tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                   tmp->play();

                   bomb(a1,jew);
                   xialuo(a1);
                   updateBaoshi(a1);
                   while(xiaochu(a1)!=0){
                       //判断连续播放 中音高音
                       i++;
                       if(i ==2){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                           tmp->play();
                       }else if(i==3){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_4.wav"));
                           tmp->play();
                       }else if(i==4){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_5.wav"));
                           tmp->play();
                       }else if(i==5){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_6.wav"));
                           tmp->play();
                       }else{
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_7.wav"));
                           tmp->play();
                       }

                        xialuo(a1);
                        updateBaoshi(a1);
                   }
                   for(int i = 0;i<8;i++){
                       for(int j = 0; j<8;j++){
                           jew[i][j]->changePicture(a1[i][j]);
                       }
                   }
                   if(fenshu>lunci*50+lunci*lunci*5){
                       fenshu+=20;
                       lunci++;
                       nextlun();
                       ui->pushButton_2->click();
                   }

               }
               else if(a1[selectX2][selectY2] == 8 && a1[selectX1][selectY1] != 8){
                   int f = a1[selectX1][selectY1]%10;
                   a1[selectX2][selectY2] = 0;
                   for(int i=0;i<8;i++){
                       for(int j=0;j<8;j++){
                           if(a1[i][j] == f) {a1[i][j] = 0;fenshu++;}
                       }
                   }
                   ui->ziji->display(fenshu);
                   int i = 0;

                   QMediaPlayer* tmp = new QMediaPlayer();
                   tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                   tmp->play();

                   bomb(a1,jew);
                   xialuo(a1);
                   updateBaoshi(a1);
                   while(xiaochu(a1)!=0){
                       //判断连续播放 中音高音
                       i++;
                       if(i ==2){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                           tmp->play();
                       }else if(i==3){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_4.wav"));
                           tmp->play();
                       }else if(i==4){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_5.wav"));
                           tmp->play();
                       }else if(i==5){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_6.wav"));
                           tmp->play();
                       }else{
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_7.wav"));
                           tmp->play();
                       }

                        xialuo(a1);
                        updateBaoshi(a1);
                   }
                   for(int i = 0;i<8;i++){
                       for(int j = 0; j<8;j++){
                           jew[i][j]->changePicture(a1[i][j]);
                       }
                   }
                   if(fenshu>lunci*50+lunci*lunci*5){
                       fenshu+=20;
                       lunci++;
                       nextlun();
                       ui->pushButton_2->click();
                   }
               }

               else if(a1[selectX2][selectY2] == 8 && a1[selectX1][selectY1] == 8)  //两个魔方宝石的消除
               {                  
                   for(int i=0;i<8;i++)
                       for(int j=0;j<8;j++){
                          a1[i][j] = 0;fenshu++;

                          QMediaPlayer* tmp = new QMediaPlayer();
                          tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                          tmp->play();

                          ui->ziji->display(fenshu);
                          QPixmap *pic
                                  = new QPixmap();
                          QString pic_path = ":/new/prefix1/media/media/partc1.png";     //加载图片路径
                          pic->load(pic_path);
                          pic->scaled(63,63);
                          QIcon buttonIcon(*pic);
                              jew[i][j]->setIcon(buttonIcon);
                          QTime time;
                          time.start();
                          while(time.elapsed() < 25){
                              QCoreApplication::processEvents();
                          }
                          pic_path = ":/new/prefix1/media/media/partc2.png";
                          pic->load(pic_path);
                          pic->scaled(63,63);
                          QIcon buttonIcon1(*pic);
                          jew[i][j]->setIcon(buttonIcon1);

                          a1[selectX2][selectY2] = 0;
                          a1[selectX1][selectY1] = 0;
                       }
                   int i = 0;

                   xialuo(a1);
                   updateBaoshi(a1);
               }

               else if(xiaochu(a1)){
                   Animation *anima = new Animation(jew[selectX1][selectY1]);
                   anima->setValue(QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102),QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102));
                   Animation *anima_2 = new Animation(jew[selectX2][selectY2]);
                   anima_2->setValue(QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102),QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102));
                   QParallelAnimationGroup *group = new QParallelAnimationGroup;
                   group->addAnimation(anima->getObj());
                   group->addAnimation(anima_2->getObj());
                   group->start();

                   QTime time;
                   time.start();
                   while(time.elapsed() < 500){
                   QCoreApplication::processEvents();
                   }

                   Jewel *t = jew[selectX1][selectY1];
                   jew[selectX1][selectY1] = jew[selectX2][selectY2];
                   jew[selectX2][selectY2] = t;
                   jew[selectX1][selectY1]->changePos(jew[selectX2][selectY2]);
                   //音乐播放逻辑
                   int i =1;
                   QMediaPlayer* tmp = new QMediaPlayer();
                   tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_2.wav"));
                   tmp->play();//要改 播放低音
//                    player_match1->play();
                   ui->ziji->display(fenshu);
                   bomb(a1,jew);
                   xialuo(a1);
                   updateBaoshi(a1);
                   while(xiaochu(a1)!=0){
                       //判断连续播放 中音高音
                       i++;
                       if(i ==2){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                           tmp->play();
                       }else if(i==3){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_4.wav"));
                           tmp->play();
                       }else if(i==4){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_5.wav"));
                           tmp->play();
                       }else if(i==5){
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_6.wav"));
                           tmp->play();
                       }else{
                           QMediaPlayer* tmp = new QMediaPlayer();
                           tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_7.wav"));
                           tmp->play();
                       }
                       ui->ziji->display(fenshu);
                        xialuo(a1);
                        updateBaoshi(a1);
                   }
                   for(int i = 0;i<8;i++){
                       for(int j = 0; j<8;j++){
                           jew[i][j]->changePicture(a1[i][j]);
                       }
                   }
                   //奖励音效
                   if(i>=2){
                       player_deletes[cur_del_mic]->play();
                       cur_del_mic = (cur_del_mic+1)%4;
                   }
                   if(fenshu>lunci*50+lunci*lunci*5){
                       lunci++;
                       nextlun();
                       fenshu+=20;
                       ui->pushButton_2->click();
                   }
               }
               else{
                   int temp = a1[selectX1][selectY1];
                   a1[selectX1][selectY1] = a1[selectX2][selectY2];
                   a1[selectX2][selectY2] = temp;//不能这样做，换回来

                   QParallelAnimationGroup *group = new QParallelAnimationGroup;
                   Animation *anima = new Animation(jew[selectX1][selectY1]);
                   anima->setValue(QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102),QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102));
                   Animation *anima_2 = new Animation(jew[selectX2][selectY2]);
                   anima_2->setValue(QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102),QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102));
                   jew[selectX1][selectY1]->changePos(jew[selectX2][selectY2]);
                   group->addAnimation(anima->getObj());
                   group->addAnimation(anima_2->getObj());
                   group->start();
                   QTime time;
                   time.start();
                   while(time.elapsed() < 700){
                   QCoreApplication::processEvents();
                   }

                       QParallelAnimationGroup *group_1 = new QParallelAnimationGroup;
                       Animation *anima_3 = new Animation(jew[selectX1][selectY1]);
                       anima_3->setValue(QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102),QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102));
                       Animation *anima_4 = new Animation(jew[selectX2][selectY2]);
                       anima_4->setValue(QPoint(67*(jew[selectX2][selectY2]->getY()+1)+175, (67*jew[selectX2][selectY2]->getX()+1)+102),QPoint(67*(jew[selectX1][selectY1]->getY()+1)+175, (67*jew[selectX1][selectY1]->getX()+1)+102));
                       group_1->addAnimation(anima_3->getObj());
                       group_1->addAnimation(anima_4->getObj());
                       group_1->start();

                       QTime time_1;
                       time_1.start();
                       while(time_1.elapsed() < 500){
                       QCoreApplication::processEvents();
                       }

                       jew[selectX1][selectY1]->changePos(jew[selectX2][selectY2]);

               }
               //动画

               //重置样式表
               jew[selectX2][selectY2]->setStyleSheet("QPushButton{border:none;background:transparent;}");
               jew[selectX1][selectY1]->setStyleSheet("QPushButton{border:none;background:transparent;}");
               selectX1 = selectX2 = selectY1 = selectY2 = -1;
           }
           else{
               jew[selectX1][selectY1]->setStyleSheet("QPushButton{border:none;background:transparent;}");
               selectX1=btn->getX();
               selectY1=btn->getY();
               jew[selectX1][selectY1]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");
               selectX2 = selectY2 = -1;
           }
       }
   }
}




void Play::slot_hint()
{
   QMessageBox message;
//    message.setIcon(QMessageBox::Icon(QIcon(":/new/prefix1/ICON/-40badbd1560d9c06.jpg")));
   message.setWindowTitle("help");
   message.setIconPixmap(QPixmap(":/new/prefix1/media/media/help.png"));
   message.exec();
}

void Play::slot_set_time()
{
}



void Play::mouseMoveEvent(QMouseEvent *ev){
  //todo
}

void Play::mousePressEvent(QMouseEvent *ev){

}

void Play::mouseReleaseEvent(QMouseEvent *ev){
   //todo
}

//QWidget* Play::getUI()
//{
//    return widget;
//}

void Play::showBaoshi(int a[8][8]){
   for(int i=0;i<8;i++){
       for(int j=0;j<8;j++){
           qDebug()<<a[i][j]<<" ";
       }
   }
}

void Play::updateBaoshi(int a[8][8]){//将0处补充为1-7的随机数
   int i,j;
   for(i=0;i<8;i++){
       for(j=0;j<8;j++){
           if(a[i][j]==0){
               a[i][j]=rand()%7+1;
           }
       }
   }
}

bool Play::checkBaoshiAfterChange(int a[8][8]){//判断交换后全局内是否可以消去，这个函数供下面这个函数使用，调用下面这个
   int b[8][8];
   for(int i=0;i<8;i++){
       for(int j=0;j<8;j++){
           b[i][j]=a[i][j];
       }
   }
   int count=xiaochu(a);
   if(count>0){
       fenshu-=count;
       return true;
   }
   else{
       return false;
   }
}

void Play::fuzhiArray(int b[8][8],int a[8][8]){//将b复制给a
   for(int i=0;i<8;i++){
       for(int j=0;j<8;j++){
           a[i][j]=b[i][j];
       }
   }
}

bool Play::checkBaoshi(int a[8][8]){//判断交换后是否可以消除，返回true or false
   int b[8][8];
   Jewel *t;
   int temp;
   bool flag = false;
   fuzhiArray(a,b);
   for(int i = 0; i < 8; i++){
       for(int j = 0; j < 8; j++){
           if(i != 7){
               temp = b[i][j];//向右交换
               b[i][j] = b[i+1][j];
               b[i+1][j] = temp;
               if(checkBaoshiAfterChange(b)){
                   selectX1=selectX2=selectY1=selectY2=-1;
                   jew[i][j]->click();
                   ui->pushButton->setEnabled(false);
                   QTime time;
                   time.start();
                   while(time.elapsed() < 250){
                   QCoreApplication::processEvents();
                   }

                   jew[i+1][j]->click();
                    ui->pushButton->setEnabled(true);
                   flag = true;
                   break;
               }
               b[i+1][j] = b[i][j];
               b[i][j] = temp;
           }
           if(i != 0){
               temp = b[i][j];//向左交换
               b[i][j] = b[i-1][j];
               b[i-1][j] = temp;
               if(checkBaoshiAfterChange(b)){
                   selectX1=selectX2=selectY1=selectY2=-1;
                   jew[i][j]->click();
                    ui->pushButton->setEnabled(false);
                   QTime time;
                   time.start();
                   while(time.elapsed() < 250){
                   QCoreApplication::processEvents();
                   }
                   jew[i-1][j]->click();;
                   ui->pushButton->setEnabled(true);
                   flag = true;
                   break;
               }
               b[i-1][j] = b[i][j];
               b[i][j] = temp;
           }
           if(j != 0){
               temp = b[i][j];//向上交换
               b[i][j] = b[i][j-1];
               b[i][j-1] = temp;
               if(checkBaoshiAfterChange(b)){
                   selectX1=selectX2=selectY1=selectY2=-1;
                   jew[i][j]->click();
                    ui->pushButton->setEnabled(false);
                   QTime time;
                   time.start();
                   while(time.elapsed() < 250){
                   QCoreApplication::processEvents();
                   }
                   jew[i][j-1]->click();
                    ui->pushButton->setEnabled(true);
                   flag = true;
                   break;
               }
               b[i][j-1] = b[i][j];
               b[i][j] = temp;
           }
           if(j != 7){
               temp = b[i][j];//向下交换
               b[i][j] = b[i][j+1];
               b[i][j+1] = temp;

               if(checkBaoshiAfterChange(b)){
                   selectX1=selectX2=selectY1=selectY2=-1;
                   jew[i][j]->click();
                                       ui->pushButton->setEnabled(false);
                   QTime time;
                   time.start();
                   while(time.elapsed() < 250){
                   QCoreApplication::processEvents();
                   }
                   jew[i][j+1]->click();
                     ui->pushButton->setEnabled(true);
                   flag = true;
                   break;
               }
               b[i][j+1] = b[i][j];
               b[i][j] = temp;
           }
       }
       if(flag){
           break;
       }
   }
   return flag;
}

void  Play::bian0(int a[8][8],int x,int y){//将一块联通区变为0，被下面的函数使用
   int value = a[x][y];
   a[x][y] = 0;
   if(a[x-1][y] == value && x-1>=0) bian0(a,x-1,y);
   if(a[x+1][y] == value && x+1 < 8) bian0(a,x+1,y);
   if(a[x][y-1] == value && y-1 >= 0) bian0(a,x,y);
   if(a[x][y+1] == value && y+1 < 8) bian0(a,x,y+1);
}

int Play::xiaochu(int a[8][8]){//消去宝石
   int count = 0;
   int teshuX[10];//记录下特殊宝石消除的位置
   int teshuY[10];
   int whatis[10];
   int teshuNum = 0;
   for(int i = 0; i < 8; i++){
       for(int j = 0; j < 8; j++){
           if(i < 6 && abs(a[i][j])%10 == abs(a[i+1][j])%10 && abs(a[i][j])%10 == abs(a[i+2][j])%10){
               if(abs(a[i][j])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i && teshuY[k] == j){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i][j]);
                       teshuX[teshuNum] = i;
                       teshuY[teshuNum] = j;
                       teshuNum++;
                   }
               }
               if(abs(a[i+1][j])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i+1 && teshuY[k] == j){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i+1][j]);
                       teshuX[teshuNum] = i+1;
                       teshuY[teshuNum] = j;
                       teshuNum++;
                   }
               }
               if(abs(a[i+2][j])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i+2 && teshuY[k] == j){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i+2][j]);
                       teshuX[teshuNum] = i+2;
                       teshuY[teshuNum] = j;
                       teshuNum++;
                   }
               }
               a[i][j] = -abs(a[i][j]);
               a[i+1][j] = -abs(a[i+1][j]);
               a[i+2][j] = -abs(a[i+2][j]);
           }
           if(j<6 && abs(a[i][j])%10 == abs(a[i][j+1])%10 && abs(a[i][j])%10 == abs(a[i][j+2])%10){
               if(abs(a[i][j])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i && teshuY[k] == j){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i][j]);
                       teshuX[teshuNum] = i;
                       teshuY[teshuNum] = j;
                       teshuNum++;
                   }
               }
               if(abs(a[i][j+1])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i && teshuY[k] == j+1){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i][j+1]);
                       teshuX[teshuNum] = i;
                       teshuY[teshuNum] = j+1;
                       teshuNum++;
                   }
               }
               if(abs(a[i][j+2])>10){
                   int flag = 0;
                   for(int k=0;k<teshuNum;k++){
                       if(teshuX[k] == i && teshuY[k] == j+2){
                           flag = 1;
                       }
                   }
                   if(flag == 0){
                       whatis[teshuNum] = abs(a[i][j+2]);
                       teshuX[teshuNum] = i;
                       teshuY[teshuNum] = j+2;
                       teshuNum++;
                   }
               }
               a[i][j] = -abs(a[i][j]);
               a[i][j+1] = -abs(a[i][j+1]);
               a[i][j+2] = -abs(a[i][j+2]);
           }
       }
   }
   //在判断雷电宝石10
  for(int i = 0; i <6; i++){
      for(int j = 0; j < 6; j++){
          if(a[i][j]<0){
              if(a[i][j]==a[i][j+1]&&a[i][j+2]==a[i][j]){
                   if(a[i][j]==a[i+1][j]&&a[i][j]==a[i+2][j]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i+1][j+1]&&a[i][j]==a[i+2][j+1]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i+2][j+2]&&a[i][j]==a[i+1][j+2]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j]&&a[i][j]==a[i-2][j]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j+1]&&a[i][j]==a[i-1][j+1]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j+2]&&a[i][j]==a[i-2][j+2]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j]&&a[i][j]==a[i+1][j]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j+1]&&a[i][j]==a[i+1][j+1]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
                   else if(a[i][j]==a[i-1][j+2]&&a[i][j]==a[i+1][j+2]){
                       int x= -a[i][j];
                       bian0(a,i,j);
                       count+=5;
                       a[i][j] = 10+x;
                   }
              }
          }
      }
  }
  //判断那些地方要生成特殊宝石,先判断>=4
  for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
          if(a[i][j] < 0){
              int lengthX = 0;
              for(int k = i; k < 8; k++){
                 if(a[k][j] == a[i][j]){
                     lengthX++;
                  }
                  else{
                   break;
                  }
              }
              int lengthY = 0;
              for(int k = j; k < 8; k++){
                  if (a[i][j] == a[i][k])
                  {
                      lengthY++;
                  }
                  else{
                   break;
                  }

              }
              if(lengthX >=5 || lengthY >= 5){
                  bian0(a,i,j);
                  a[i][j] = 8;//特殊爆炸宝石8
                  count+=5;
              }
              else{
                  if(lengthX == 4 || lengthY ==4){
                      int x = -a[i][j];
                      bian0(a,i,j);
                      a[i][j] = 20+x;
                      count+=4;
                  }
              }

          }
      }
  }
  //特殊宝石消除
  for(int i =0;i<teshuNum;i++){
      if(abs(whatis[i])/10==1){
          for(int j=0;j<8;j++){
             a[j][teshuY[i]]= 0;
             a[teshuX[i]][j] = 0;
             if(j!=teshuX[i]) count+=2;
             else count++;
          }
      }
      else{
           for(int k=max(teshuX[i]-1,0);k<=min(7,teshuX[i]+1);k++){
               for(int j = max(0,teshuY[i]-1);j<=min(teshuY[i]+1,7);j++){
                   a[k][j] = 0;
                   count++;
               }
           }
      }
  }


   for(int  i = 0; i<8; i++){
       for(int j = 0; j < 8; j++){
           if(a[i][j] < 0){
               a[i][j] = 0;
               count++;
           }
       }
   }
   fenshu+= count;
   return count;
}

int Play::weizhiX(int x){
   return 67*(x+1)+36;
}

int Play::weizhiY(int y){
   return 67*(y+1)+175;
}

void Play::xialuo(int a[8][8],int init){//用于实现下落
       int x[8];
       int y[8] = {0};//记录下落距离
       for(int i=0;i<8;i++){
           x[i] = -1;
           y[i] = 0;
       }
       for(int j = 0; j < 8; j++){
           for(int i = 7; i >= 0; i--){
               if(a[i][j] == 0){
                   if(x[j] == -1){
                       for(int k = i; k >= 0; k--){
                           if(a[k][j] == 0){
                               y[j]++;
                           }
                       }
                       x[j] = i;
                   }
                   for(int k = i; k >= 0; k--){
                       if(a[k][j] != 0){
                           a[i][j] = a[k][j];//从k，j下落到i，j
                           a[k][j] = 0;
                           break;
                       }
                   }
               }
           }
       }
       QPropertyAnimation *anim1[64];
       QParallelAnimationGroup *group = new QParallelAnimationGroup;
       updateBaoshi(a);
       for(int i = 0;i<8;i++){
           for(int j = 0; j<8;j++){
               jew[i][j]->changePicture(a[i][j]);
           }
       }
       if(init == 0){//只有
           int index = 0;
           for(int j=0;j<8;j++){
               for(int i = x[j];i>=0;i--){
                   anim1[index] = new QPropertyAnimation(jew[i][j],"geometry");
                   anim1[index]->setDuration(500);
                   anim1[index]->setStartValue(QRect(weizhiY(j), weizhiX(i-y[j]), 61, 61));
                   anim1[index]->setEndValue(QRect(weizhiY(j), weizhiX(i), 61, 61));
                   group->addAnimation(anim1[index]);
                   index++;
               }
           }
           group->start();
           QTime time;
           time.start();
           while(time.elapsed() < 600){
               QCoreApplication::processEvents();
           }
       }



}

//实现槽函数
void Play::slot_music_on()
{
//     player_backMusics[cur_music]->play();
   player_backMusic1->play();
}

void Play::slot_music_off()
{
//    player_backMusics.at(cur_music)->stop();
   player_backMusic1->stop();
}

void Play::slot_music_change()
{
   playlist->next();

}

//void Form::slot_hint()
//{
//    QMessageBox message;
////    message.setIcon(QMessageBox::Icon(QIcon(":/new/prefix1/ICON/-40badbd1560d9c06.jpg")));
//    message.setWindowTitle("help");
//    message.setIconPixmap(QPixmap(":/new/prefix1/media/media/help.png"));
//    message.exec();
//}


void Play::on_pushButton_2_clicked()
{
   if(fenshu>=20){
       fenshu-=20;
       ui->ziji->display(fenshu);
       for(int i=0;i<8;i++){
              for(int j=0;j<8;j++){
                  a1[i][j] = 0;
              }
          }
       int x[8];
       int y[8] = {0};//记录下落距离
       for(int i=0;i<8;i++){
           x[i] = -1;
           y[i] = 0;
       }
       for(int j = 0; j < 8; j++){
           for(int i = 7; i >= 0; i--){
               if(a1[i][j] == 0){
                   if(x[j] == -1){
                       for(int k = i; k >= 0; k--){
                           if(a1[k][j] == 0){
                               y[j]++;
                           }
                       }
                       x[j] = i;
                   }
                   for(int k = i; k >= 0; k--){
                       if(a1[k][j] != 0){
                           a1[i][j] = a1[k][j];//从k，j下落到i，j
                           a1[k][j] = 0;
                           break;
                       }
                   }
               }
           }
       }
       QPropertyAnimation *anim1[64];
       QParallelAnimationGroup *group = new QParallelAnimationGroup;
       updateBaoshi(a1);
       for(int i = 0;i<8;i++){
           for(int j = 0; j<8;j++){
               jew[i][j]->changePicture(a1[i][j]);
           }
       }
       if(true){//只有
           int index = 0;
           for(int j=0;j<8;j++){
               for(int i = x[j];i>=0;i--){
                   anim1[index] = new QPropertyAnimation(jew[i][j],"geometry");
                   anim1[index]->setDuration(500+50*(8-i));
                   anim1[index]->setStartValue(QRect(weizhiY(j), weizhiX(i-y[j]), 61, 61));
                   anim1[index]->setEndValue(QRect(weizhiY(j), weizhiX(i), 61, 61));
                   group->addAnimation(anim1[index]);
                   index++;
               }
           }
           group->start();
           QTime time;
           time.start();
           while(time.elapsed() < 1000){
               QCoreApplication::processEvents();
           }
       }
          if(xiaochu(a1)){
              //音乐播放逻辑
              int i =1;
              QMediaPlayer* tmp = new QMediaPlayer();
              tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_2.wav"));
              tmp->play();//要改 播放低音
      //                    player_match1->play();
               ui->ziji->display(fenshu);
              xialuo(a1);
              updateBaoshi(a1);
              while(xiaochu(a1)!=0){
                  //判断连续播放 中音高音
                  i++;
                  if(i ==2){
                      QMediaPlayer* tmp = new QMediaPlayer();
                      tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_3.wav"));
                      tmp->play();
                  }else if(i==3){
                      QMediaPlayer* tmp = new QMediaPlayer();
                      tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_4.wav"));
                      tmp->play();
                  }else if(i==4){
                      QMediaPlayer* tmp = new QMediaPlayer();
                      tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_5.wav"));
                      tmp->play();
                  }else if(i==5){
                      QMediaPlayer* tmp = new QMediaPlayer();
                      tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_6.wav"));
                      tmp->play();
                  }else{
                      QMediaPlayer* tmp = new QMediaPlayer();
                      tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_7.wav"));
                      tmp->play();
                  }
                   ui->ziji->display(fenshu);
                   xialuo(a1);
                   updateBaoshi(a1);
              }
              for(int i = 0;i<8;i++){
                  for(int j = 0; j<8;j++){
                      jew[i][j]->changePicture(a1[i][j]);
                  }
              }
              //奖励音效
              if(i>=2){
                  player_deletes[cur_del_mic]->play();
                  cur_del_mic = (cur_del_mic+1)%4;
              }
          }
          if(fenshu>lunci*50+lunci*lunci*5){
              fenshu+=20;
              lunci++;
              nextlun();
              ui->pushButton_2->click();
          }
   }else{
       //播放分数不够的音效
   }

}


void Play::nextlun(){
   ui->label_3->setText("时间限制:"+QString::number(lunci)+"分钟");
   ui->label_2->setText("当前目标分数:"+QString::number(lunci*50+lunci*lunci*5));
}

void Play::on_start_clicked()
{
    qDebug()<<fuhuo;
   if(!begin){
       if(fuhuo==0){
           time1 = new QTimer(this);
           time1->start(100);
           connect(time1, &QTimer::timeout, [=]() {
               run_time_s_ += 0.1;
               // 保留小数点后三位显示
               QString str_run_time_s = QString::number(run_time_s_, 'f', 3);
               ui->timer->display(str_run_time_s);
               int run_time = run_time_s_;
               int h = run_time / (60 * 60);
               int m = (run_time - (h * 60 * 60)) / 60-fuhuo;
               int s = (run_time - (h * 60 * 60)) - (m+fuhuo) * 60;
               // 整数前面补0
               QString str_run_time = QString("%1").arg(h, 2, 10, QLatin1Char('0')) + ":"
                   + QString("%1").arg(m, 2, 10, QLatin1Char('0')) + ":"
                   + QString("%1").arg(s, 2, 10, QLatin1Char('0'));
               ui->timer->display(str_run_time);
               if(m>=lunci){
                   QMediaPlayer* tmp = new QMediaPlayer();
                   tmp->setMedia(QUrl("qrc:/new/prefix1/music/5538.wav"));
                   tmp->play();
                   player_backMusic1->stop();
                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::information(this, tr("QMessageBox::information()"),"wasted");
                   time1->stop();
                   for(int i=0;i<8;i++){
                       for(int j=0;j<8;j++){
                           jew[i][j]->setEnabled(false);
                       }
                   }
                   fuhuo += m;
                   begin=false;
                   ui->start->setText("重新开始");
               }
           });
            updateBaoshi(a1);
           for(int i = 0; i <8; i++){
               for(int j = 0; j < 8; j++){
                   jew[i][j] = new Jewel(i,j,a1[i][j],1);
                   scene_3->addWidget(jew[i][j]->getbutton());
               }
           }
           for(int i = 0;i<8;i++){
               for(int j = 0; j<8;j++){
                   jew[i][j]->changePicture(a1[i][j]);
               }
           }
           //绑定槽函数
           for(int i = 0; i <8; i++){
               for(int j = 0; j < 8; j++){
                        connect(jew[i][j],SIGNAL(jewPosSignal(int ,int )),this,SLOT(change(int ,int )));
                        connect(this,SIGNAL(statusCursorCchanger(int)),jew[i][j],SLOT(changeCursor(int)));
                        connect(jew[i][j],SIGNAL(changeBack(int,int)),this,SLOT(resetCursor(int,int)));
               }
           }
           fenshu+=20;
           ui->pushButton_2->click();
       }
       else{
           for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    jew[i][j]->setEnabled(true);
                }
           }
            ui->start->setText("开始");
            fenshu=20;
            lunci=1;
            nextlun();
            time1->start();
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    a1[i][j]=0;
                }
            }
            ui->pushButton_2->click();
       }
       begin = true;
   }
}


void Play::on_pushButton_clicked()
{
   checkBaoshi(a1);
}


void Play::on_mofangtool_clicked()
{
    if(cursor_status == 0 && magicTool_num > 0){
        cursor_status = 1;
        magicTool_num -= 1;
        ui->label_4->setText(QString("魔法\n道具*").append(QString::number(magicTool_num)));
        QPixmap pixmap;
        pixmap.load(":/new/prefix1/media/media/Magic.png");
        pixmap = pixmap.scaled(QSize(50,50));
        QCursor cursor1(pixmap);
        ui->graphicsView->viewport()->setCursor(cursor1);
        setCursor(cursor1);
        for(int i=0 ; i<8;i++){
            for(int j =0 ; j<8;j++){
                jew[i][j]->setCursor(cursor1);
            }
        }
        QApplication::setOverrideCursor(cursor1);
        emit statusCursorCchanger(cursor_status);
    }
}

void Play::resetCursor(int x, int y){
        cursor_status = 0;
        QPixmap pixmap;
        pixmap.load(":/new/prefix1/media/media/handCursor.png");
        pixmap = pixmap.scaled(QSize(50,50));
        QCursor cursor2(pixmap);
        QApplication::setOverrideCursor(cursor2);
        setCursor(cursor2);
        for(int i=0 ; i<8;i++){
            for(int j =0 ; j<8;j++){
                jew[i][j]->setCursor(cursor2);
            }
        }
        emit statusCursorCchanger(cursor_status);
        a1[x][y] =8;
        jew[x][y]->changePicture(8);
}

void Play::bomb(int b[8][8], Jewel *baoshi[8][8])
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(b[i][j] == 0) {
                baoshi[i][j]->bomb();
            }

    QTime time_1;
    time_1.start();
    while(time_1.elapsed() < 100){
        QCoreApplication::processEvents();
    }

}
