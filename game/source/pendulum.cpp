/*
Calculate the length of a simple pendulum
End with "0" input
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> //M_PIが定義されている

double gravity = 9.8;
double calculate(double);//プロトタイプ宣言

int main(void) {
    double T;//Tは周期
    double length;//振り子の長さ
    printf("\n*************************************************\n");
    printf("\n*Start calculate the length of a simple pendulum*\n");
    printf("\n****************End with 0 input*****************\n");
    printf("\n*************************************************\n");

    while (1) {
        printf("\nPlease enter a number(0<number)\n");
        //&Tより、Tのアドレスの場所に数値を格納
        scanf("%lf", &T);//周期を入力
        printf("\nPendulum period is %lf [s]\n", T);//周期を表示
        if (T == 0) break;//0を押すと処理を終了
        else if (T > 0) {
            length = calculate(T);
            printf("\nPendulum length is %lf [m]\n", length);
        }
        else {
            printf("\nPlease enter a value greater than or equal to 0\n");
            }
    }
    return 0;
END: ;
}

double calculate(//float型は4バイト、doublue型は8バイト
    double T//Tは周期
)
{
    /*
    単振り子の計算式
    T=2π×√(l/g)
    l= (T^2×g)/(4π^2)
    */
   double length;//lengthの単位は[m]
   length = (pow(T, 2.0)*gravity)/(4*pow(M_PI, 2.0)); 
   return length;
}
