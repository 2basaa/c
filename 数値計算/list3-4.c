#include <stdio.h>

void main() {
	int dice;
	printf("1����U���̒l����͂��Ă��������F");
	scanf("%d", &dice);
	if (1 <= dice && dice <= 6){
		if (dice == 2 || dice == 4 || dice == 6){
			printf("���ł��B\n");
		}
		else {
			printf("���ł��B\n");
		}
	}
	else {
		printf("�͈͊O�̐��l�ł��B\n");
	}
}
