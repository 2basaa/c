#include <stdio.h>

void main (){
	int a;
	printf("数値を入力：");
	scanf("%d", &a);
	if (a > 0) {
		printf("入力した値は正です。\n");
	}
	else {
		printf("入力した値は正ではありません。\n");
	}
}
