#include <stdio.h>

void main () {
	int num;
	printf("���̒l�ŁA���[�v���甲���܂��B\n");
	while(1){
		printf("���l����́F");
		scanf("%d", &num);
		if (num < 0) {
			break;
		}
	}
	printf("�I��\n");
}
