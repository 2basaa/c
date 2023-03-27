/*コンピュータとじゃんけんアプリをする*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void judge(int, int);

int main (void) {
    int myNumber, comNumber;//自分と相手のじゃんけんの手
    printf("\n########computer and rock paper scissors########\n");
    printf("\n#Exit with input other than [0] and [1] and [2]#\n");
    while (1)
    {
        printf("Enter decimal number\n");
        scanf("%d", &myNumber);//myNumberの場所に値を格納
        //0をグー、1をパー、2をチョキ
        if (myNumber > 2) break;
        printf("\n0=goo, 1=paa, 2=choki: %d", myNumber);
        comNumber = rand() % 3;//0から２の値を取る
        judge(myNumber, comNumber);
    }   
    return 0;
}

void judge(int myNum, int comNum) {
    //自分が勝った場合
    if ((myNum == 0 && comNum == 2) || 
        (myNum == 1 && comNum == 0) ||
        (myNum == 2 && comNum == 1)) {
            printf("\nyou won!!\n");
        }
    //あいこの場合
    else if (myNum == comNum) {
        printf("\naiko!!\n");
    }
    else {
        printf("\nyou lose!!\n");
    }
}
