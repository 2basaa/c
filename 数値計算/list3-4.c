#include <stdio.h>

void main() {
	int dice;
	printf("1から６くの値を入力してください：");
	scanf("%d", &dice);
	if (1 <= dice && dice <= 6){
		if (dice == 2 || dice == 4 || dice == 6){
			printf("丁です。\n");
		}
		else {
			printf("半です。\n");
		}
	}
	else {
		printf("範囲外の数値です。\n");
	}
}
