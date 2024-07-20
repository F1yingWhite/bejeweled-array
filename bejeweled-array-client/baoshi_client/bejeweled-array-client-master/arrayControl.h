#ifndef ARRAYCONTROL_H
#define ARRAYCONTROL_H

#include <iostream>
#include <QDebug>
#include <cstdlib>// Header file needed to use rand
#include <ctime> // Header file needed to use time
using namespace std;
void showBaoshi(int a[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            qDebug()<<a[i][j]<<" ";
        }
        qDebug()<<endl;
    }
}

void updateBaoshi(int a[8][8]){//将0处补充为1-7的随机数
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(a[i][j]==0){
                a[i][j]=rand()%7+1;
            }
        }
    }
}

bool checkBaoshiAfterChange(int a[8][8]){//判断交换后全局内是否可以消去
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

void fuzhiArray(int b[8][8],int a[8][8]){//将b复制给a
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=b[i][j];
        }
    }
}

bool checkBaoshi(int a[8][8]){//判断是否可以消除
    int b[8][8];
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

void  bian0(int a[8][8],int x,int y){//将一块联通区变为0
    int value = a[x][y];
    a[x][y] = 0;
    if(a[x-1][y] == value && x-1>=0) bian0(a,x-1,y);
    if(a[x+1][y] == value && x+1 < 8) bian0(a,x+1,y);
    if(a[x][y-1] == value && y-1 >= 0) bian0(a,x,y);
    if(a[x][y+1] == value && y+1 < 8) bian0(a,x,y+1);
}

int xiaochu(int a[8][8]){//消去宝石
    int count = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i < 6 && abs(a[i][j]) == abs(a[i+1][j]) && abs(a[i][j]) == abs(a[i+2][j])){
                a[i][j] = -abs(a[i][j]);
                a[i+1][j] = -abs(a[i+1][j]);
                a[i+2][j] = -abs(a[i+2][j]);
            }
            if(j<6 && abs(a[i][j]) == abs(a[i][j+1]) && abs(a[i][j]) == abs(a[i][j+2])){
                a[i][j] = -abs(a[i][j]);
                a[i][j+1] = -abs(a[i][j+1]);
                a[i][j+2] = -abs(a[i][j+2]);
            }
        }
    }
    //判断那些地方要生成特殊宝石,先判断》=4
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[i][j] < 0){
                int lengthX = 0;
                for(int k = i; k < 8; k++){
                   if(a[k][j] == a[i][j]){
                       lengthX++;
                    }
                }
                int lengthY = 0;
                for(int k = j; k < 8; k++){
                    if (a[i][j] == a[i][k])
                    {
                        lengthY++;
                    }

                }
                if(lengthX >=5 || lengthY >= 5){
                    bian0(a,i,j);
                    a[i][j] = 8;//特殊爆炸宝石8
                }
                else{
                    if(lengthX == 4 || lengthY ==4){
                        bian0(a,i,j);
                        a[i][j] = 9;
                    }
                }

            }
        }
    }
//在判断雷电
    for(int i = 2; i <6; i++){
        for(int j = 2; j < 6; j++){
            if(a[i][j]<0){
                if(((a[i][j] == a[i][j+1] && a[i][j] == a[i][j+1])||(a[i][j] == a[i][j-1] && a[i][j] == a[i][j-2]))
                        && ((a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j])||(a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j]))){
                    bian0(a,i,j);
                    a[i][j] = 10;
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
    return count;
}

void xialuo(int a[8][8]){
    for(int j = 0; j < 8; j++){
        for(int i = 7; i >= 0; i--){
            if(a[i][j] == 0){
                for(int k = i; k >= 0; k--){
                    if(a[k][j] != 0){
                        a[i][j] = a[k][j];
                        a[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    unsigned seed;
    seed = time(0);
    srand(seed);
    int baoshi[8][8] = {0};
    updateBaoshi(baoshi);
    showBaoshi(baoshi);
    qDebug()<<checkBaoshi(baoshi)<<endl;
    qDebug()<<endl;
    xiaochu(baoshi);
    showBaoshi(baoshi);
    qDebug()<<endl;
    xialuo(baoshi);
    showBaoshi(baoshi);
    return 0;
}



#endif // ARRAYCONTROL_H
