#include <stdio.h>

void main () {
	int num;
	printf("1�`3�̒l����͂��Ă��������F");
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
		default://������̏����ɂ����Ă͂܂�Ȃ�����defalut�Ƃ���B 
			printf("�s�K�؂Ȓl�ł��B\n");
			break;
	}
}
