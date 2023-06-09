#include <stdio.h>
#include <math.h>
#define N 11

/*基本関数の関数値を求める*/
void ffv(int p, double a, double *b) {
	switch(p) {
		case 1: *b = a;   break;
		case 2: *b = 1.0/a;   break;
		case 3: *b = exp(a);   break;
		case 4: *b = 1.0;   break;
		default: *b = a;
	}
}

int main(void) {
	int f,g,n,i,j,l;
	double xx,yy,p,q,h,s,fx,gx,c[4][4],d[4];
	double x[N], y[N], x2[N], x3[N], a[N][4], b[4][N];
	double xi;
	char z,zz;
	
	printf("このプログラムは最小２乗法によって \n");
	printf("y = a*f(x) + b*g(x) \n");
	printf("この形の曲線を当てはめるものです \n\n");
	printf("基本関数f(x), g(x)を1〜4の番号で選択してください \n");
	
	while(1) {
		printf("f(x)=[1:(x), 2:(1/x), 3:(e^x)]--> ");
		scanf("%d%c", &f, &zz);
		if((1 <= f) && (f <= 3)) break;
	}

	while(1) {
		printf("g(x)=[1:(x), 2:(1/x), 3:(e^x), 4(定数)]--> ");
		scanf("%d%c", &g, &zz);
		if((1 <= g) && (g <= 4)) break;
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
			ffv(f, xi, &fx);
			ffv(g, xi, &gx);
			
			x2[i] = fx;
			x3[i] = gx;
			
			a[i][1] = x2[i];
			a[i][2] = x3[i];
			a[i][3] = y[i];
			
			b[1][i] = a[i][1];
			b[2][i] = a[i][2];	
		}
		printf("\n　正しく入力しましたか？(y/n) ");
		scanf("%c%c", &z, &zz);
		if (z == 'y') break;
	}
	/*tA/Aを計算して配列c[2][3]に入れる*/
	for(i=1; i<= 2; i++) {
		for(j=1; j<=3; j++) {
			s = 0.0;
			for(l=1; l<=n; l++) {
				s = s + b[i][l] * a[l][j];
			}
			c[i][j] = s;
		}
	}	
	/*正規方程式をガウスジョルダン法で解く*/
	for(i=1; i<=2; i ++) {
		p = c[i][i];
		for(j=1; j<= 3; j++) {
			c[i][j] = c[i][j] / p;
		}
		for(l=1; l<=2; l++) {
			if(l != i) {
				q = c[l][i];
				for(j=i; j<= 3; j++) {
					c[l][j] = c[l][j] - q*c[i][j];
				}
			}
		}
	}
	
	/*答えを配列d[1], d[2]に入れる*/
	for(i=1; i<=2; i++) {
		d[i] = c[i][3];
	}
	printf("\n 求めた基本関数の係数の出力\n");
	printf("a = d[1] = %lf\n", d[1]);
	printf("b = d[2] = %lf\n", d[2]);
	printf(" \n エンターキーで出力 \n");
	scanf("%c", &zz);
	
	/*数表の出力*/
	h = (x[n] - x[1]) / 50.0;
	xx = x[1];
	for(i=0; i<=50; i++) {
		ffv(f, xx, &fx);
		ffv(g, xx, &gx);
		yy = d[1] * fx + d[2] *gx;
		printf("%lf\t%lf\n", xx, yy);
		xx = xx + h;
	}
}
