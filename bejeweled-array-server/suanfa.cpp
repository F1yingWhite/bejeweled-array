#include <iostream>
#include <cstdlib>// Header file needed to use rand
#include <ctime> // Header file needed to use time
using namespace std;
void showBaoshi(int a[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void updateBaoshi(int a[8][8]){//��0������Ϊ1-7�������
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(a[i][j]==0){
                a[i][j]=rand()%7+1;
            }
        }
    }
}

bool checkBaoshiAfterChange(int a[8][8]){//�жϽ�����ȫ�����Ƿ������ȥ
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

void fuzhiArray(int b[8][8],int a[8][8]){//��b���Ƹ�a
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=b[i][j];
        }
    }
}

bool checkBaoshi(int a[8][8]){//�ж��Ƿ��������
    int b[8][8];
    int temp;
    bool flag = false;
    fuzhiArray(a,b);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i != 7){
                temp = b[i][j];//���ҽ���
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
                temp = b[i][j];//���󽻻�
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
                temp = b[i][j];//���Ͻ���
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
                temp = b[i][j];//���½���
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

void  bian0(int a[8][8],int x,int y){//��һ����ͨ����Ϊ0
    int value = a[x][y];
    a[x][y] = 0;
    if(a[x-1][y] == value && x-1>=0) bian0(a,x-1,y);
    if(a[x+1][y] == value && x+1 < 8) bian0(a,x+1,y);
    if(a[x][y-1] == value && y-1 >= 0) bian0(a,x,y);
    if(a[x][y+1] == value && y+1 < 8) bian0(a,x,y+1);
}

int xiaochu(int a[8][8]){//��ȥ��ʯ
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
    //�ж���Щ�ط�Ҫ�������ⱦʯ,���жϡ�=4
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
                    a[i][j] = 8;//���ⱬը��ʯ8
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
//���ж��׵�
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
    cout<<checkBaoshi(baoshi)<<endl;
    cout<<endl;
    xiaochu(baoshi);
    showBaoshi(baoshi);
    cout<<endl;
    xialuo(baoshi);
    showBaoshi(baoshi);
    return 0;
}

