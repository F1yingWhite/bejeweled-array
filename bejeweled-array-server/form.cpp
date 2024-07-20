#include "form.h"
#include "ui_form.h"
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
#include <qtimer.h>
#include <QTimer>
#include<QParallelAnimationGroup>
#include<string.h>
using namespace std;
QGraphicsScene *scene_1;
QGraphicsScene *scene_2;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    this->setWindowTitle("宝石迷阵");
    this->setWindowIcon(QIcon(":/new/prefix1/ICON/13369429051CA2411D99F227A90D19CB9BE4EA10C2.jpg"));
    ui->setupUi(this);
    socket=new QTcpSocket();
    ui->timer->setStyleSheet("QLCDNumber{border:none;background:transparent;}");

    //连接信号槽
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Form::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Form::socket_Disconnected);

    ui->lineEdit_Ip->setText("6000");
    ui->pushButton_Listen->setText("OpenServer");

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
    scene_1 = new QGraphicsScene(ui->graphicsView);
    scene_1->setSceneRect(0,67,830,620);
    ui->graphicsView->setScene(scene_1);

    //添加对方宝石,
    scene_2 = new QGraphicsScene(ui->graphicsView_2);
    scene_2->setSceneRect(900,67,630,620);
    ui->graphicsView_2->setScene(scene_2);

    seed = time(0);
    srand(seed);
    seed1 = seed;
    updateBaoshi(a);
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            jew[i][j] = new Jewel(i,j,a[i][j],1);
            scene_1->addWidget(jew[i][j]->getbutton());
        }
    }
    if(xiaochu(a,1)){
        xialuo(a,1,1);
        while(xiaochu(a,1)!=0){
             xialuo(a,1,1);
        }
    }
    //绑定槽函数
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
           connect(jew[i][j],SIGNAL(jewPosSignal(int ,int )),this,SLOT(send(int ,int )));
           connect(jew[i][j],SIGNAL(jewPosSignal(int ,int )),this,SLOT(change(int ,int )));
        }
    }
    //添加对方宝石
    updateBaoshi(a2);
    for(int i = 0; i <8; i++){
        for(int j = 0; j < 8; j++){
            jew2[i][j] = new Jewel(i,j,a2[i][j],2);
            scene_2->addWidget(jew2[i][j]->getbutton());
        }
    }
    if(xiaochu(a2,2)){
        xialuo(a2,2,1);
        while(xiaochu(a2,2)!=0){
             xialuo(a2,2,1);
        }
    }
    for(int i = 0;i<8;i++){
        for(int j = 0; j<8;j++){
            jew2[i][j]->changePicture(a2[i][j]);
        }
    }
    for(int i = 0;i<8;i++){
        for(int j = 0; j<8;j++){
            jew[i][j]->changePicture(a[i][j]);
        }
    }


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
    QCursor cursor(pixmap);

    setCursor(cursor);


    //更新字体
    QFont font = ui->ziji->font();
    QString family = QApplication::applicationDirPath() + ":/new/prefix1/media/media/fuentelcd.ttf";
    font.setFamily(family);
    ui->ziji->setFont(font);//设置控件自定义字体
    fenshu2 = 0;
    fenshu1 = 0;
}

Form::~Form()
{
    server->close();
    server->deleteLater();
    delete ui;
}



//连接
void Form::on_pushButton_Listen_clicked()
{
    if(ui->pushButton_Listen->text() == tr("OpenServer"))
    {
        server = new QTcpServer();

        //连接信号槽
        connect(server,&QTcpServer::newConnection,this,&Form::server_New_Connect);
//        ui->textEdit_Recv->insertPlainText("OpenSuccessfully\n");
        //从输入框获取端口号
//        int port = ui->lineEdit_Port->text().toInt();
        int port  = ui->lineEdit_Ip->text().toInt();
        //监听指定的端口
        if(!server->listen(QHostAddress::Any, port))
        {
            //若出错，则输出错误信息
            QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
            QMessageBox::information(this,tr("消息"),tr("打开服务器失败！"),QMessageBox::Yes);
            return;
        }
        //修改按键文字
       ui->pushButton_Listen->setText("CloseServer");
       QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
       QMessageBox::information(this,tr("消息"),tr("打开服务器成功！"),QMessageBox::Yes);
    }
    else
    {
        server->deleteLater();
        //取消侦听
        server->close();
        //修改按键文字
        ui->pushButton_Listen->setText("OpenServer");
        //发送按键失能
//        ui->pushButton_Send->setEnabled(false);
//        ui->textEdit_Recv->insertPlainText("CloseSuccessfully\n");
    }

}

void Form::change(int x,int y){
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
                int temp = a[selectX1][selectY1];
                a[selectX1][selectY1] = a[selectX2][selectY2];
                a[selectX2][selectY2] = temp;//交换矩阵
                if(a[selectX1][selectY1] == 8){
                    int f = a[selectX2][selectY2];
                    a[selectX1][selectY1] = 0;
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j] == f) {a[i][j] = 0;fenshu1++;}
                        }
                    }
                    int i = 0;
                    bomb(a,jew);
                    xialuo(a,1);
                    updateBaoshi(a);
                    while(xiaochu(a,1)!=0){
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

                         xialuo(a,1);
                         updateBaoshi(a);
                    }
                    for(int i = 0;i<8;i++){
                        for(int j = 0; j<8;j++){
                            jew[i][j]->changePicture(a[i][j]);
                        }
                    }

                }
                else if(a[selectX2][selectY2] == 8){
                    int f = a[selectX1][selectY1];
                    a[selectX2][selectY2] = 0;
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j] == f) {a[i][j] = 0;fenshu1++;}
                        }
                    }
                    int i = 0;
                    bomb(a,jew);
                    xialuo(a,1);
                    updateBaoshi(a);
                    while(xiaochu(a,1)!=0){
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

                         xialuo(a,1);
                         updateBaoshi(a);
                    }
                    for(int i = 0;i<8;i++){
                        for(int j = 0; j<8;j++){
                            jew[i][j]->changePicture(a[i][j]);
                        }
                    }
                }
                else if(xiaochu(a,1)){
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
                    ui->ziji->display(fenshu1);
//                    player_match1->play();
                    bomb(a,jew);
                    xialuo(a,1);
                    updateBaoshi(a);
                    while(xiaochu(a,1)!=0){
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
                         ui->ziji->display(fenshu1);
                         xialuo(a,1);
                         updateBaoshi(a);
                    }
                    for(int i = 0;i<8;i++){
                        for(int j = 0; j<8;j++){
                            jew[i][j]->changePicture(a[i][j]);
                        }
                    }
                    //奖励音效
                    if(i>=2){
                        player_deletes[cur_del_mic]->play();
                        cur_del_mic = (cur_del_mic+1)%4;
                    }
                }
                else{                    
                    int temp = a[selectX1][selectY1];
                    a[selectX1][selectY1] = a[selectX2][selectY2];
                    a[selectX2][selectY2] = temp;//不能这样做，换回来

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

void Form::remoteChange(int x,int y){
    Jewel* btn = jew2[x][y];// 获取到了发送该信号按钮的指针
    QMediaPlayer* tmp= new QMediaPlayer();
    tmp->setMedia(QUrl("qrc:/new/prefix1/music/match2.wav"));
    tmp->setVolume(30);
    tmp->play();
    if(btn->where == 2){
        if(selectX12 == -1){
            selectX12=btn->getX();
            selectY12=btn->getY();
            jew2[selectX12][selectY12]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");//改变样式表
        }
        else if(selectX22 == -1){
            selectX22 = btn->getX();
            selectY22 = btn->getY();
            if((selectX12==selectX22-1&&selectY22==selectY12)||(selectX12==selectX22+1&&selectY22==selectY12)||(selectX12==selectX22&&selectY22-1==selectY12)||(selectX12==selectX22&&selectY22+1==selectY12)){
                jew2[selectX22][selectY22]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");
                int temp = a2[selectX12][selectY12];
                a2[selectX12][selectY12] = a2[selectX22][selectY22];
                a2[selectX22][selectY22] = temp;//交换矩阵
                if(xiaochu(a2,2)){
                    Animation *anima = new Animation(jew2[selectX12][selectY12]);
                    anima->setValue(QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102),QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102));
                    Animation *anima_2 = new Animation(jew2[selectX22][selectY22]);
                    anima_2->setValue(QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102),QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102));
                    QParallelAnimationGroup *group = new QParallelAnimationGroup;
                    group->addAnimation(anima->getObj());
                    group->addAnimation(anima_2->getObj());
                    group->start();

                    QTime time;
                    time.start();
                    while(time.elapsed() < 500){
                    QCoreApplication::processEvents();
                    }

                    Jewel *t = jew2[selectX12][selectY12];
                    jew2[selectX12][selectY12] = jew2[selectX22][selectY22];
                    jew2[selectX22][selectY22] = t;
                    jew2[selectX12][selectY12]->changePos(jew2[selectX22][selectY22]);
                    //音乐播放逻辑
                    int i =1;
                    QMediaPlayer* tmp = new QMediaPlayer();
                    tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_2.wav"));
                    tmp->play();//要改 播放低音
                    ui->ziji_2->display(fenshu2);
//                    player_match1->play();
                    bomb(a2,jew2);
                    xialuo(a2,2);
                    while(xiaochu(a2,2)!=0){
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
                         ui->ziji_2->display(fenshu2);
                         xialuo(a2,2);
                         updateBaoshi(a2);
                    }
                    for(int i = 0;i<8;i++){
                        for(int j = 0; j<8;j++){
                            jew2[i][j]->changePicture(a2[i][j]);
                        }
                    }
                    //奖励音效
                    if(i>=2){
                        player_deletes[cur_del_mic]->play();
                        cur_del_mic = (cur_del_mic+1)%4;
                    }
                }
                else{
                    int temp = a2[selectX12][selectY12];
                    a2[selectX12][selectY12] = a2[selectX22][selectY22];
                    a2[selectX22][selectY22] = temp;//不能这样做，换回来

                    QParallelAnimationGroup *group = new QParallelAnimationGroup;
                    Animation *anima = new Animation(jew2[selectX12][selectY12]);
                    anima->setValue(QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102),QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102));
                    Animation *anima_2 = new Animation(jew2[selectX22][selectY22]);
                    anima_2->setValue(QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102),QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102));
                    jew2[selectX12][selectY12]->changePos(jew2[selectX22][selectY22]);
                    group->addAnimation(anima->getObj());
                    group->addAnimation(anima_2->getObj());
                    group->start();
                    QTime time;
                    time.start();
                    while(time.elapsed() < 700){
                    QCoreApplication::processEvents();
                    }

                        QParallelAnimationGroup *group_1 = new QParallelAnimationGroup;
                        Animation *anima_3 = new Animation(jew2[selectX12][selectY12]);
                        anima_3->setValue(QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102),QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102));
                        Animation *anima_4 = new Animation(jew2[selectX22][selectY22]);
                        anima_4->setValue(QPoint(67*(jew2[selectX22][selectY22]->getY()+1)+879, (67*jew2[selectX22][selectY22]->getX()+1)+102),QPoint(67*(jew2[selectX12][selectY12]->getY()+1)+879, (67*jew2[selectX12][selectY12]->getX()+1)+102));
                        group_1->addAnimation(anima_3->getObj());
                        group_1->addAnimation(anima_4->getObj());
                        group_1->start();

                        QTime time_1;
                        time_1.start();
                        while(time_1.elapsed() < 500){
                        QCoreApplication::processEvents();
                        }

                        jew2[selectX12][selectY12]->changePos(jew2[selectX22][selectY22]);

                }
                //动画

                //重置样式表
                jew2[selectX22][selectY22]->setStyleSheet("QPushButton{border:none;background:transparent;}");
                jew2[selectX12][selectY12]->setStyleSheet("QPushButton{border:none;background:transparent;}");
                selectX12 = selectX22 = selectY12 = selectY22 = -1;
            }
            else{
                jew2[selectX12][selectY12]->setStyleSheet("QPushButton{border:none;background:transparent;}");
                selectX12=btn->getX();
                selectY12=btn->getY();
                jew2[selectX12][selectY12]->setStyleSheet("QPushButton{border:none;background:transparent;border:3px solid #66FFFF;}");
                selectX22 = selectY22 = -1;
            }
        }
    }
    qDebug()<<selectX12<<" "<<selectY12<<" "<<selectX22<<" "<<selectY22;
}

void Form::send(int x, int y){
    QString info = QString::number(x);
    info.append(",").append(QString::number(y)).append(",");
    socket->write(info.toLocal8Bit());
    socket->flush();
    this->ui->lineEdit_Ip->setText(info);
}

void Form::server_New_Connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();
    //连接QTcpSocket的信号槽，以读取新数据
    QObject::connect(socket, &QTcpSocket::readyRead, this, &Form::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Form::socket_Disconnected);

        QString info = QString::number(seed);
        qDebug()<<info<<endl;
        socket->write(info.toLocal8Bit());
        socket->flush();
    isInit = true;

    //发送按键使能
//    ui->pushButton_Send->setEnabled(true);

}

void Form::socket_Read_Data()
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = QString::fromLocal8Bit(buffer);
        QStringList strList = str.split(",");
        QString ans = strList[0].append(" ").append(strList[1]);
        if(str.at(0).isDigit()){
            remoteChange(strList[0].left(1).toInt(),strList[1].toInt());
        }
    }
}

void Form::socket_Disconnected()
{
    //发送按键失能
// todo 等待判定
}

//实现槽函数
void Form::slot_music_on()
{
//     player_backMusics[cur_music]->play();
    player_backMusic1->play();
}

void Form::slot_music_off()
{
//    player_backMusics.at(cur_music)->stop();
    player_backMusic1->stop();
}

void Form::slot_music_change()
{
    playlist->next();

}

void Form::slot_hint()
{
    QMessageBox message;
//    message.setIcon(QMessageBox::Icon(QIcon(":/new/prefix1/ICON/-40badbd1560d9c06.jpg")));
    message.setWindowTitle("help");
    message.setIconPixmap(QPixmap(":/new/prefix1/media/media/help.png"));
    message.exec();
}

void Form::slot_set_time()
{
}



void Form::mouseMoveEvent(QMouseEvent *ev){
   //todo
}

void Form::mousePressEvent(QMouseEvent *ev){

}

void Form::mouseReleaseEvent(QMouseEvent *ev){
    //todo
}

void Form::showBaoshi(int a[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            qDebug()<<a[i][j]<<" ";
        }
    }
}

void Form::updateBaoshi(int a[8][8]){//将0处补充为1-7的随机数
    bool flag=false;
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(a[i][j]==0 || a[i][j] == -1){
                if(!flag){
                    qDebug()<<"seed1:"<<seed1;
                    seed1++;
                    srand(seed1);
                    flag = true;
                }
                a[i][j]=rand()%7+1;
                qDebug()<<"random"<<a[i][j];
            }
        }
    }
}

bool Form::checkBaoshiAfterChange(int a[8][8]){//判断交换后全局内是否可以消去，这个函数供下面这个函数使用，调用下面这个
    bool flag = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i < 6 && a[i][j] == a[i+1][j] && a[i][j] == a[i+2][j]){
                flag = true;
            }
            if(j<6 && a[i][j] == a[i][j+1] && a[i][j] == a[i][j+2]){
                flag = true;
            }
        }
    }
    return flag;
}

void Form::fuzhiArray(int b[8][8],int a[8][8]){//将b复制给a
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=b[i][j];
        }
    }
}

bool Form::checkBaoshi(int a[8][8]){//判断交换后是否可以消除，返回true or false
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

void  Form::bian0(int a[8][8],int x,int y){//将一块联通区变为0，被下面的函数使用
    int value = a[x][y];
    a[x][y] = 0;
    if(a[x-1][y] == value && x-1>=0) bian0(a,x-1,y);
    if(a[x+1][y] == value && x+1 < 8) bian0(a,x+1,y);
    if(a[x][y-1] == value && y-1 >= 0) bian0(a,x,y);
    if(a[x][y+1] == value && y+1 < 8) bian0(a,x,y+1);
}

int Form::xiaochu(int a[8][8],int k){//消去宝石
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
    for(int  i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            if(a[i][j] < 0){
                a[i][j] = 0;
                count++;
            }
        }
    }
    if(k==1) {
        fenshu1+=count;
    }
    else {fenshu2+=count;}
    return count;
}

int weizhiX(int x){
    return 67*(x+1)+36;
}

int weizhiY(int y){
    return 67*(y+1)+175;
}

void Form::xialuo(int a[8][8],int type,int init){//用于实现下落
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
                        QPixmap *pic
                                = new QPixmap();
                        QString pic_path = ":/new/prefix1/media/media/partc1.png";     //加载图片路径
                        pic->load(pic_path);
                        pic->scaled(63,63);
                        QIcon buttonIcon(*pic);
                        if(type==1){
                            jew[i][j]->setIcon(buttonIcon);
                        }else{
                            jew2[i][j]->setIcon(buttonIcon);
                        }
                        QTime time;
                        time.start();
                        while(time.elapsed() < 50){
                            QCoreApplication::processEvents();
                        }
                        pic_path = ":/new/prefix1/media/media/partc2.png";
                        pic->load(pic_path);
                        pic->scaled(63,63);
                        QIcon buttonIcon1(*pic);
                        if(type==1){
                        jew[i][j]->setIcon(buttonIcon1);
                        }else{
                            jew2[i][j]->setIcon(buttonIcon1);
                        }
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

        QTime time;
        time.start();
        while(time.elapsed() < 100){
            QCoreApplication::processEvents();
        }
        QString pic_path;
        QPropertyAnimation *anim1[64];
        QParallelAnimationGroup *group = new QParallelAnimationGroup;
        updateBaoshi(a);
        for(int i = 0;i<8;i++){
            for(int j = 0; j<8;j++){
                if(type==1)  jew[i][j]->changePicture(a[i][j]);
                else jew2[i][j]->changePicture(a[i][j]);
            }
        }
        if(init == 0){//只有
            int index = 0;
            for(int j=0;j<8;j++){
                for(int i = x[j];i>=0;i--){
                    if(type==1)  anim1[index] = new QPropertyAnimation(jew[i][j],"geometry");
                    else anim1[index] = new QPropertyAnimation(jew2[i][j],"geometry");
                    anim1[index]->setDuration(500);
                    if(type==1){
                        anim1[index]->setStartValue(QRect(weizhiY(j), weizhiX(i-y[j]), 61, 61));
                        anim1[index]->setEndValue(QRect(weizhiY(j), weizhiX(i), 61, 61));
                    }
                    else{
                        anim1[index]->setStartValue(QRect(weizhiY2(j), weizhiX(i-y[j]), 61, 61));
                        anim1[index]->setEndValue(QRect(weizhiY2(j), weizhiX(i), 61, 61));
                    }
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

int Form::weizhiY2(int j){
    return 67*(j+1)+879;
}

void Form::on_pushButton_2_clicked()
{
    if(fenshu1>=20){
        fenshu1-=20;
        ui->ziji->display(fenshu1);
        for(int i=0;i<8;i++){
               for(int j=0;j<8;j++){
                   a[i][j] = 0;
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
                if(a[i][j] == 0){
                    jewel[i][j] = 0;
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
                            a[k][j] = -1;
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
           if(xiaochu(a,1)){
               //音乐播放逻辑
               int i =1;
               QMediaPlayer* tmp = new QMediaPlayer();
               tmp->setMedia(QUrl("qrc:/new/prefix1/music/combo_2.wav"));
               tmp->play();//要改 播放低音
       //                    player_match1->play();
                ui->ziji->display(fenshu1);
               xialuo(a,1);
               updateBaoshi(a);
               while(xiaochu(a,1)!=0){
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
                    ui->ziji->display(fenshu1);
                    xialuo(a,1);
                    updateBaoshi(a);
               }
               for(int i = 0;i<8;i++){
                   for(int j = 0; j<8;j++){
                       jew[i][j]->changePicture(a[i][j]);
                   }
               }
               //奖励音效
               if(i>=2){
                   player_deletes[cur_del_mic]->play();
                   cur_del_mic = (cur_del_mic+1)%4;
               }
           }

    }else{
        //播放分数不够的音效
    }

}


void Form::on_start_clicked()
{
    if(!begin){
        time1 = new QTimer(this);
        QString info = "s";
        socket->write(info.toLocal8Bit());
        socket->flush();
        this->ui->lineEdit_Ip->setText(info);
        time1->start(100);
        connect(time1, &QTimer::timeout, [=]() {
            run_time_s_ += 0.1;
            // 保留小数点后三位显示
            QString str_run_time_s = QString::number(run_time_s_, 'f', 3);
            ui->timer->display(str_run_time_s);
            int run_time = run_time_s_;
            int h = run_time / (60 * 60);
            int m = (run_time - (h * 60 * 60)) / 60;
            int s = (run_time - (h * 60 * 60)) - m * 60;
            // 整数前面补0
            QString str_run_time = QString("%1").arg(h, 2, 10, QLatin1Char('0')) + ":"
                + QString("%1").arg(m, 2, 10, QLatin1Char('0')) + ":"
                + QString("%1").arg(s, 2, 10, QLatin1Char('0'));
            ui->timer->display(str_run_time);
        });
        begin = true;
    }
}

void Form::bomb(int b[8][8], Jewel *baoshi[8][8])
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(b[i][j] == 0) {
                baoshi[i][j]->bomb();
            }

    QTime time_1;
    time_1.start();
    while(time_1.elapsed() < 50){
        QCoreApplication::processEvents();
    }

}
