#include <stdio.h>
#include <math.h>

#define N 10

#include "my_library.h"

int main (void) {
	int n, i, j;
	//a is argumented matrix(�g��s��)(n,n+1)
	//a[][N+1] is solution
	static double a[N][N + 1], x[N] ;
	char z, zz;
	
	while(1) {
		printf("�K�E�X�̏����ɂ��A���������̉�@\n");
		printf("�쌳�A���������ł���(1 < n < 9) n = ");
		scanf("%d%c", &n, &zz);
		if ((n <= 1) || (N -1 <= n)) continue;
		printf("\n�W������͂��Ă�������\n\n");
		//�g��s��(n,n+1)���쐬
		for (i = 1; i <= n +1; i ++) {
			for (j = 1; j <= n + 1; j ++) {
				printf("a(%d, %d)=", i, j);
				scanf("%lf%c", &a[i][j], &zz);
			}	
			printf("\n");
		}
		printf("���������͏o���܂�����?(y/n)");
		//y��n�̓���
		scanf("%c%c", &z,&zz);
		if(z == 'y') break;	
	}
	
	//�K�E�X�̏����@�����s
	int ret = gaussian_elimination(a,n);
	if (ret != 0) {
		return ret;
	}
	//�t�i������s���A��x[i]�����߂�
	inverse_substitution(a, x, n);
	
	/*���̕\��*/
	printf("\n�A���������̉�\n\n");
	for(i = 1; i<= n; i ++) {
		printf("x(%d) = %10.61f\n", i , x[i]);
	} 
	return 0;
}
