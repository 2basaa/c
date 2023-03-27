#include <stdio.h>
#include <math.h>
#define N 10
#include "my_library_v3.h"

/*��{�֐��̊֐��l�����߂�*/
double ffv(int fi, double x) {
	double y;
	switch(fi) {
		case 1: y = 1.0;   break;
		case 2: y = x;   break;
		case 3: y = x*x;   break;
		case 4: y = x*x*x;   break;
		case 5: y = 1.0/x; break;
		case 6:	y = exp(x); break;
		default: y = x;
	}
	return y;
}

int main(void) {
	int f,g,n,i,j,l;
	double xx,yy,p,q,h,s,fx;
	double x[N] = {0}, y[N] = {0}, b[N] = {0},f_id[N] = {0};
	double xi;
	char z,zz;
	int k ,num;
	double A[N][N] = {0}, tA[N][N] = {0}; 
	double tAA[N][N] ={0}, tAb[N]= {0}, tb[N][N] = {0};
	double sol[N] = {0};
	
	printf("���f���Ŏg�p�����{�֐��̌�����͂��ĉ����� \n");
	scanf("%d%c", &k, &zz) ;
	
	printf("���̃v���O�����͍ŏ��Q��@�ɂ���� \n");
	printf("y = a1*f1(x) + a2*f2(x)+...+ an*fn(x) \n");
	printf("���̌`�̋Ȑ��𓖂Ă͂߂���̂ł� \n\n");
	printf("��{�֐�f(x)��1�`6�̔ԍ��őI�����Ă������� \n");
	
	for (j = 1; j <= k; j ++) {
		while(1) {
			printf("f(x)=[1:1.0, 2:x, 3:x*x, 4. x*x*x, 5.1.0/x, 6.exp(x)  --> ");
			scanf("%d%c", &f, &zz);
			f_id[j] = f; 
			if((1 <= f) && (f <= 6)) break;
		}
	}

	/*�f�[�^�̓��́u*/
	while(1) {
		printf("�f�[�^�̌��͉��ł����H�@(1<n<11) n = ");
		scanf("%d%c", &n, &zz);
		if((n <=1) || (n >= 11)) continue;
		printf("\n�f�[�^x�̒l�͏������̏��ɓ��͂���B \n");
		for(i=1; i<= n; i++) {
			printf("X = "); scanf("%lf%c", &x[i], &zz);
			printf("Y = "); scanf("%lf%c", &y[i], &zz);
			/*�֐��Ăяo��*/
			xi = x[i];
			b[i] = y[i];
			for (j = 1; j <= k; j ++) {
				A[i][j] = ffv(f_id[j],xi);
				tA[j][i] = A[i][j];
			}		
		}
		printf("\n�@���������͂��܂������H(y/n) ");
		scanf("%c%c", &z, &zz);
		if (z == 'y') break;
	}
	for (num = 1; num <= k; num ++) {
		for (j = 1; j <= k ; j ++) {
			for (i = 1; i <= n; i++) {
				tAA[num][j] += tA[num][i] * A[i][j];  	
			}
		}
	}
	
	for (j = 1; j <= k; j++) {
		for (i = 1; i <= n; i ++) {
			tAb[j] += tA[j][i] * b[i]; 
		}
	}
	
	
	lu_solve(k, tAA,tAb,sol);
	
	printf("\n ���߂���{�֐��̌W���̏o��\n");
	for (j = 1; j <= k; j ++) {
		printf("sol = %lf\n", sol[j]);	
	}
	printf(" \n �G���^�[�L�[�ŏo�� \n");
	scanf("%c", &zz);
	
	/*���\�̏o��*/
	h = (x[n] - x[1]) / 50.0;
	xx = x[1];
	for(i=0; i<=50; i++) {
		yy = 0;
		for (j = 1; j <=k ; j ++) {
			fx = ffv(f_id[j], xx);
			yy += sol[j] * fx ; 
		}
		printf("%lf\t%lf\n", xx, yy);
		xx = xx + h;
	}
}
