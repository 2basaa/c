#include <stdio.h>

void main () {
	int num;
	printf("1～3の値を入力してください：");
	scanf("%d", &num);
	switch (num){
		case 1:
			printf("one\n");
			break;
		case 2:
			printf("two\n");
			break;
		case 3:
			printf("three\n");
			break;
		default://いずれの条件にも当てはまらない時をdefalutとする。 
			printf("不適切な値です。\n");
			break;
	}
}
