#include <stdio.h>

void main () {
	int i,j;
	for (i = 1; i <= 2; i++) {
		for (j = 2; j <= 3; j ++) {
			printf("%d+%d=%d\n", i,j,i+j);
		}
	}
}
