/****************************/
/*アスキ―アート　　　　　　 */
/*                          */
/*敵UFO   キャラクター:M    */
/*        ビーム: $$$　　　 */
/*プレイヤー　キャラクター:A*/
/*            ビーム: |||　 */
/*キー操作　　左右移動: ←,→ */
/*            ビーム発射: ↑ */
/*            終了:Esc      */
/*UFOは離れたら戻ってくる　 */
/****************************/

//conio.hは、コンソール入出力関数
//string.hは、memcpyなどで使用
//stdio.hは、出力
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define XMAX 80
#define YMAX 24

int main(void)
{
    //[row][col]rowは行、colは列
    char buf[YMAX] [XMAX];//行列(フィールド)
    int xM = 10, yM = 0;//キャラクタM 位置
    int dxM = 1;//M 移動量(左右)
    int xMb, yMb=YMAX; //ビーム$位置
    int xA=20, yA=YMAX - 1;//キャラクタA 位置
    int xAb, yAb = -1;//A ビーム| 位置
    int col, number;//文字配列展示

    while (1)
    {
        /**********ビームやキャラクタの配置************/
        system("cls"); // 画面消去

        //memset(void *buf, int ch, size_t n);
        //*bufはメモリブロック
        //chは文字, nはバイト数
        memset(&buf[0][0], ' ', XMAX*YMAX);//文字配列クリア
        buf[yM][xM] = 'M'; //[yM][xM]の位置にMを出力
        buf[yA][xA] = 'A';//キャラクタA配置
        if (yMb < YMAX){//Mのビーム
            buf[yMb][xMb] = '$'; //$を配置 
            if (xMb>1) buf[yMb][xMb-1] = '$';
            if (xMb<XMAX) buf[yMb][xMb+1] = '$';
        }
        if (yAb >= 0) {//Aのビーム
            buf[yAb][xAb] = '|';
            if (xAb > 1) buf[yAb][xAb-1]='|';
            if (xAb<XMAX) buf [yAb][xAb+1]='|';
        }
        
        /**************当たり判定の作成***************/
        for (col=0; col<YMAX; col++){
            //&buf[col][0]の中からXMAX個を出力
            //%.*sで&bu[col][0]の中からXMXだけ出力
            printf("%.*s", XMAX, &buf[col][0]);
        }
        fflush(stdout);  
        //Mに|が当たった時
        if (yM == yAb) {
            //xAb-1<=xM<=xAb+1
            if (xM>=xAb-1 && xM<=xAb+1) {
                Beep(784, 1000);
                break;
            }
        }

        //Aに$が当たった時
        if (yA == yMb) {
            //xMb-1<=xA<=xMb+1
            if (xA>= xMb-1 && xA <= xMb+1){
                Beep(330, 1000);
                break;
            }
        }

        //|と$が当たった時
        if (abs(yAb-yMb)<= 1) {
            //xMb-2<=xAb<=xMb+2
            if (xAb>=xMb-2 && xAb<=xMb+2) {
                Beep(588, 100);
                //↓の処理は画面外に出す処理
                yAb=-1; yMb=YMAX;//ビーム消失
            }
        }

        /********ビームと敵の動きの処理***********/
        if (xM == 0 || xM ==79) dxM = -dxM;//M 両端で反転
        else if (xM-xA > 15) dxM = -1; //M,A 右に離れた
        else if (xM-xA < -15) dxM = 1; //M,A 左に離れた
        xM += dxM;// Mの位置を更新
        if (yMb<YMAX) yMb += 1; //$を1行下へ
        if(yAb>=0) yAb -= 1; //|を1行上へ
        /********キーが押された時のA動作************/
        //kbhit()!=0でキーが押された
        if (kbhit() != 0){
            number = getch(); //キーが押された
            if (number == 27) break;//Esc(終了)
            if (number == 0) number=getch();//特殊キー
            if (number == 75) {//←
                xA -= 3; //A 3桁左へ
                if (xA<0) xA=0; //左端
            }
            else if (number == 77) {//→
                xA += 3; //A 3桁右へ
                if (xA>=XMAX) xA=XMAX-1; //右端 
            }
            if (number == 72 && yAb<0) {//↑, |なし
                xAb = xA; yAb = yA-1;//発射
            }
        }
        if (xA==xM && yMb>=YMAX) {//A,M x同位置, $なし
            xMb=xM; yMb=1; //$発射
        }
        Sleep(50);
    }   
    return 0;
}
