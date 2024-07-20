#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMenu>
#include <QVideoWidget>
#include <QAction>
#include <QMenuBar>
#include "jewel.h"
#include <QMediaPlayer>
#include <QVector>
#include <QMessageBox>
#include <QMediaPlaylist>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);

    static QWidget* getUI();                   //动画制作提供ui



    ~Form();

private slots:
//    void OpenToWork(){
//        start_timi->play();
//        player_backMusics[cur_music]->play();
//        this->setFixedWidth(830);
//        this->show();
//    }
    void OpenToWork2(){
        start_timi->play();
        player_backMusic1->play();
//        player_backMusics[cur_music]->play();
        this->show();
    }
    void on_pushButton_Listen_clicked();
    void remoteChange(int x,int y);

//    void on_pushButton_Send_clicked();

    void server_New_Connect();

    void socket_Read_Data();

    void socket_Disconnected();

    void send(int x,int y);

    void change(int x,int y);
    //槽函数声明

    void slot_music_on();

    void slot_music_off();

    void slot_music_change();

    void slot_hint();

    void slot_set_time();


    void on_pushButton_2_clicked();

    void on_start_clicked();

private:
    Ui::Form *ui;
    QTcpServer* server;
    QTcpSocket* socket;
    static Form* widget;
    double run_time_s_ = 0;
    QTimer *time1;
    //添加menu
    QMenu *setting;
    QMenu *help;
    QAction *music_on;
    QAction *music_off;
    QAction *music_turn;
    QAction *hint;
    QAction *Qtime;
    int fenshu2 = 0;
    int fenshu1 = 0;
    bool begin = false;
    int a[8][8] = {0};//用于存放宝石的数组
    Jewel *jew[8][8];
    int selectX1 = -1;
    int selectY1 = -1;
    int selectX2 = -1;
    int selectY2 = -1;

    int a2[8][8] = {0};//用于存放宝石的数组
    Jewel *jew2[8][8];
    int selectX12 = -1;
    int selectY12 = -1;
    int selectX22 = -1;
    int selectY22 = -1;

    int jewel[8][8] = {0};

    //初始化音乐播放器
    QVector<QMediaPlayer*>  player_deletes ;
    int cur_del_mic=0;
    int music_num = 0;
    int cur_music =0;
    QMediaPlayer* start_timi = new QMediaPlayer();
    QMediaPlayer* player_backMusic1 = new QMediaPlayer();
    QMediaPlayer* player_match1 = new QMediaPlayer();
    QMediaPlayer* player_match2 = new QMediaPlayer();
    QMediaPlayer* player_match3 = new QMediaPlayer();
    QMediaPlayer* player_match4 = new QMediaPlayer();
    QMediaPlayer* player_match5 = new QMediaPlayer();
    QMediaPlayer* player_match6 = new QMediaPlayer();
    QMediaPlaylist* playlist = new QMediaPlaylist;
    QMediaPlayer* player_click = new QMediaPlayer();
    QMediaPlayer* player_select = new QMediaPlayer();
    QMediaPlayer* player_delete1 = new QMediaPlayer();
    QMediaPlayer* player_delete2 = new QMediaPlayer();
    QMediaPlayer* player_delete3 = new QMediaPlayer();
    QMediaPlayer* player_delete4 = new QMediaPlayer();
    QMediaPlayer* fail = new QMediaPlayer();
    int seed =0;
    int seed1;
    bool isInit = false;


protected:
        //鼠标移动事件 xyh
    void mouseMoveEvent(QMouseEvent *ev);
        //鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);
        //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);

public:
    bool checkBaoshiAfterChange(int a[8][8]);

    bool checkBaoshi(int a[8][8]);

    void  bian0(int a[8][8],int x,int y);

    int xiaochu(int a[8][8],int k);

    void xialuo(int a[8][8],int type,int init = 0);

    void updateBaoshi(int a[8][8]);

    void showBaoshi(int a[8][8]);

    void fuzhiArray(int b[8][8],int a[8][8]);

    void bomb(int b[8][8], Jewel *baoshi[8][8]);

    int weizhiY2(int j);
};

#endif // FORM_H
