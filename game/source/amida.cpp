/*
あみだくじ作成
*は道となる
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LMAX 5 //縦線の最大数
#define CMAX 15 //桁の最大値
#define rowMax 25//行
#define colMax 50//列

char root[rowMax][colMax];//あみだくじのルート作成
int dsx = colMax / (LMAX - 1);//切り捨て 商は12

void INIroot(void);
void KUJI(int);
void DISP(void);

int main(void) {
    char c[128];
    int N;
    printf("\namidakuji\n");

    INIroot();
    DISP();
    while(1) {
        printf("\nPlease input number(finish except 1~%d) :", LMAX);
        fflush(stdout);
        gets(c);
        N=atoi(c);//文字列を数字に変更
        if (N<1 || N > LMAX) break;//終了
        
        KUJI(N);//くじをなぞる
        DISP();//画面表示
    }
}

void INIroot() {
    /*領域設定*/
    int col, row, y, x;//colは列,rowは行
    //unsigned long seed;//乱数の種

	time_t seed;
    memset(&root[0][0], ' ', colMax*rowMax);//領域を初期化
    //縦線
    for (col=0, x=0; col<LMAX; col++, x+=dsx) {
        for(y=0; y<rowMax; y++) root[y][x] = '*';
    }
    //横線
    time(&seed);//時刻取得
    srand(seed);//乱数の種をまく
    for (row = 0; row < CMAX; ) {
        col = row % (LMAX-1);//縦線添字(0~3)
        x = col * dsx; //縦線の位置
        y = rand()%rowMax-1;//横線の位置 
        //↓では交点を見つけると、以下の処理を実行
        if (root[y][x]=='+' || root[y][x+dsx]=='+')
            continue;
        memset(&root[y][x], '*', dsx);//横線設定
        root[y][x] = '+';
        root[y][x+dsx] = '+';
        row++;
    }
}

void KUJI(int N /*くじをなぞる*/) {
    int x, y, dx, dy;//位置、増分

    x = dsx*(N-1); y = 0; //開始位置
    dx = 0; dy = 1;//進行位置

    while (y<rowMax)  
    {
        if ( root[y][x] != '+') {
            root[y][x]='0' + N;//通貨番号設定
        }
        else {//横に移動
            if (dy == 0) {
                dx=0; dy=1;//下へ方向変換
            }
            else {//下に移動
                dx = 1; dy = 0;//右へ方向変換
                if (x > 0) {//左端でない
                    if (root[y][x-1] != ' ') {//左に線あり
                        dx = -1;//左へ方向転換
                    }
                }
            }
        }
        x+=dx; y+=dy; //移動
    }   
}
//画面表示
void DISP() {
    char c[128];
    int num, x, y;
    //番号表示
    memset(c, ' ', colMax); 
    c[colMax] = '\0';//番号一桁
    for(num=0,x=0; num<LMAX; num++, x+=dsx) {
        c[x] ='1'+num; //一桁表示
    }
    printf("\n%.*s\n", x, c);

    //領域表示
    for (y = 0; y<rowMax; y ++) {
        printf("\n%.*s", colMax, &root[y][0]);//1行表示
    }
    printf("\n");
    //結果表示
    memset(c, ' ', colMax); //番号１行
    c[colMax] = '\0';
    for (num=0,x=0; num<LMAX; num++,x+=dsx) {
        c[x]='A'+num;
    }
    printf("\n%.*s", x, c);//一桁表示
}
