#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include "jewel.h"
#include <QMediaPlayer>
#include <QVector>
#include <QMessageBox>
#include <qtimer.h>
#include <QMediaPlaylist>
namespace Ui {
class Play;
}

class Play : public QWidget
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);

    static QWidget* getUI();                   //动画制作提供ui

    int weizhiX(int);

    int weizhiY(int);

    ~Play();
signals:
    void statusCursorCchanger(int c);

private slots:
    void OpenToWork1(){
        start_timi->play();
        player_backMusic1->play();
        this->show();
    }
    void resetCursor(int x,int y);
    void change(int x,int y);
    //槽函数声明

    void slot_music_on();

    void slot_music_off();

    void slot_music_change();

    void slot_hint();

    void slot_set_time();


    void on_pushButton_2_clicked();

    void on_start_clicked();

    void on_pushButton_clicked();

    void on_mofangtool_clicked();

private:
    Ui::Play *ui;
    static Play* widget;

    //添加menu
    QMenu *setting;
    QMenu *help;
    QAction *music_on;
    QAction *music_off;
    QAction *music_turn;
    QAction *hint;
    QAction *Qtime;
    double run_time_s_ = 0;
    QTimer *time1;
    bool begin = false;
    int fenshu = 0;
    int a1[8][8] = {0};//用于存放宝石的数组
    Jewel *jew[8][8];
    int selectX1 = -1;
    int selectY1 = -1;
    int selectX2 = -1;
    int selectY2 = -1;
    int lunci = 1;
    int fuhuo=0;

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
    int seed1 =0;
    bool isInit = false;
    int cursor_status = 0;
    int magicTool_num = 3;


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

    int xiaochu(int a[8][8]);

    void xialuo(int a[8][8], int init = 0);

    void updateBaoshi(int a[8][8]);

    void showBaoshi(int a[8][8]);

    void fuzhiArray(int b[8][8],int a[8][8]);

    void nextlun();

    void bomb(int a[8][8], Jewel *baoshi[8][8]);


};

#endif // Play_H
