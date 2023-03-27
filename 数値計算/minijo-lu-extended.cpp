#include <stdio.h>
#include <math.h>
#define N 10
#include "my_library_v3.h"

/*基本関数の関数値を求める*/
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
	
	printf("モデルで使用する基本関数の個数を入力して下さい \n");
	scanf("%d%c", &k, &zz) ;
	
	printf("このプログラムは最小２乗法によって \n");
	printf("y = a1*f1(x) + a2*f2(x)+...+ an*fn(x) \n");
	printf("この形の曲線を当てはめるものです \n\n");
	printf("基本関数f(x)を1～6の番号で選択してください \n");
	
	for (j = 1; j <= k; j ++) {
		while(1) {
			printf("f(x)=[1:1.0, 2:x, 3:x*x, 4. x*x*x, 5.1.0/x, 6.exp(x)  --> ");
			scanf("%d%c", &f, &zz);
			f_id[j] = f; 
			if((1 <= f) && (f <= 6)) break;
		}
	}

	/*データの入力「*/
	while(1) {
		printf("データの個数は何個ですか？　(1<n<11) n = ");
		scanf("%d%c", &n, &zz);
		if((n <=1) || (n >= 11)) continue;
		printf("\nデータxの値は小から大の順に入力する。 \n");
		for(i=1; i<= n; i++) {
			printf("X = "); scanf("%lf%c", &x[i], &zz);
			printf("Y = "); scanf("%lf%c", &y[i], &zz);
			/*関数呼び出し*/
			xi = x[i];
			b[i] = y[i];
			for (j = 1; j <= k; j ++) {
				A[i][j] = ffv(f_id[j],xi);
				tA[j][i] = A[i][j];
			}		
		}
		printf("\n　正しく入力しましたか？(y/n) ");
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
	
	printf("\n 求めた基本関数の係数の出力\n");
	for (j = 1; j <= k; j ++) {
		printf("sol = %lf\n", sol[j]);	
	}
	printf(" \n エンターキーで出力 \n");
	scanf("%c", &zz);
	
	/*数表の出力*/
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
