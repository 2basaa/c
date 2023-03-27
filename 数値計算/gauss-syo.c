#include <stdio.h>
#include <math.h>
#define N  10

void irekae(double a[][N+1], int i, int n) {
	int m, j, k;
	double key;
	m = i;
	/*絶対値の最大を探す*/
	for (k = i+ 1; k <= n; k ++) {
		if (fabs(a[m][i]) < fabs(a[k][i])){
			m = k;
		}
	}		
/*m行とi行の入れ替え*/
	for (j = 1; j <= n + 1; j ++) {
		key = a[m][j];
		a[m][j] = a[i][j];
		a[i][j] = key;
	} 
}

int main (void) {
	int n, i, j ;
	static double a[N][N + 1], x{N] ;
	char z, zz;
	
	while(1) {
		printf("ガウスの消去による連立方程式の解法\n");
		printf("南元連立方程式ですか(1 < n < 9) n = ");
		scanf("%d%c", &n, &zz);
		if ((n <= 1) || (N -1 <= n)) continue;
		printf("\n係数を入力してください\n\n");
		for (i = 1; i <= n +1; i ++) {
			for (j = 1; j <= n + 1; j ++) {
				printf("a(%d, %d)=", i, j);
				scanf("%lf%c", &a[i][j], &zz);
			}	
			printf("\n");
		}
		printf("正しく入力出来ましたか?(y/n)");
		scanf("%c%c", &z,&zz);
		if(z == 'y') break;	
	}
	
	int ret = gaussian_elimination(a,n);
	if (ret != 0) {
		return ret;
	}
	inverse_substitution(a, x, n);
	
	/*解の表示*/
	printf("\n連立方程式の解\n\n");
	for(i = 1; i<= n; i ++) {
		printf("x(%d) = %10.61f\n", i , x[i]);
	} 
	return 0;
}

//makes matrix"a" upper triangular by Gaussian eliminataion
// n is the number of rows

int gaussian_elimination(double a[][N + 1], int n) {
	double p, q;
	int i, j, k;
	/*対角成分から下を吐き出して上三角行列の形に変形*/
	for ( i = 1; i <= n; i ++) {
		irekae(a,i,n);
		p = a[i][i];
		if(fabs(p) < 1.0e-6) {
			printf("一意解を持ちません\n");
			return -1;
		}
	/*第i行を(i,i)成分で割る*/
		for (j = i;j <= n + 1; j ++) {
			a[i][j] = a[i][j] / p;	
		}  
		for (k = i + 1; k <= n; k ++) {
			q = a[k][i];
			for(j = 1; j <= n + 1;j ++) {
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
	}
	return 0;
}
//requires "a" to be an upper triangular matrix
//x is the output vector
//n is the number of rows
void inverse_substitution(double a[][N + 1], double x[N], int n) {
	int i,j;
	double s;
	/*逆進代入による計算*/
	for (i = n; i>= 1; i--) {
		s = 0.0;
		for (j = i + 1; j <= n; j ++){
			s += a[i][j] * x[j];
		}
		x[i] = a[i][n+1] - s;
	}	
}}
