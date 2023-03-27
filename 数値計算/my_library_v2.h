#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

/*my_library version 2.0*/

void irekae (double a[][N + 1], int i, int n) {
	/*
	m is row
	j is col
	k(i+1<=k<=n) change row
	*/
	int m, j, k;
	double key;
	m = i;
	/*絶対値が最大の物を探す*/
	for (k = i + 1;k <= n; k ++) {
		if (fabs(a[m][i]) < fabs(a[k][i])) {
			m = k;
		}
	} 
	//最大値と指定した行を変換
	/*第m行と第i行の入れ替え*/
	for (j = 1; j <= n + 1; j ++) {
		key = a[m][j];
		a[m][j] = a[i][j];
		a[i][j] = key;
 	}
}

// makes matrix "a" upper triangular by Gaussian elimination
// n is the number of rows

int gaussian_elimination(double a[][N+1], int n) {
	/*
	a[][N+1] is augmented matrix(拡大行列)(n,n+1)
	p is a[i][i] = 1
	q is a[k][i](i+1<=k<=n)
	j is col of value
	k is row of value
	*/
	double p, q;
	int i, j, k;
	/*対角成分より下を吐き出して上三角秒列の形に変形*/
	for (i = 1; i <= n; i ++) {
		//i列の中で最大値を探して、最大値となる行とi行の値を変換
		irekae(a, i, n);
		p = a[i][i];
		//|p|<10^(-6) process break
		if(fabs(p) < 1.0e-6) {
			printf("一意解を持たない\n");
			return -1;
		}
	/*第i行を(i,i)成分で割る*/
		for(j = i; j <= n+1; j ++) {
			a[i][j] = a[i][j] / p;
		}
		//a[i+1]=0(i+1行以降)を作成
		for (k = i+1; k <= n; k ++) {
			q = a[k][i];
			for(j = 1;j <= n+1; j ++) {
				a[k][j] = a[k][j] - a[i][j] * q;
			}
		}
	}
	return 0;
}

//requires "a" to be an upper triangular matrix
//x is the output vector
//n is the number of rows
void inverse_substitution (double a[][N+1], double x[N], int n) {
	int i , j;
	double s;
	/*逆進代入による計算*/
	for (i = n; i >= 1; i--) {
		s = 0.0;
		for (j = i+1; j<= n; j ++) {
			s += a[i][j] * x[j];
		}
		//xの値を得る
		/*a[i][n+1]は解b[i]となる
		  x[i]=b[i]-s
		  x[n]=b[n]
		  x[n-j]=b[n-j]-Σ(n-j+1<=k<=n)a[n-j][k]*x[k]*/
		x[i] = a[i][n+1] - s;
	}
}

/*行列の入力*/
int input_matrix(double a[N][N]) {
	int n, i, j;
	char z, zz;
	while(1) {
		printf("行列の次数の入力(1 < n < %d) n =", N - 1);
		//zとzzをget
		scanf("%d%c", &n, &zz);
		if((n <= 1) || (N-1 <= n)) continue;
		printf("\n行列Aの成分を入力\n\n");
		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= n; j ++) {
				printf("a(%d, %d)=", i, j);
				scanf("%lf%c", &a[i][j], &zz);
			}
			printf("\n");
		}
		printf("正しく入力しましたか？(y/n)");
		scanf("%c%c", &z, &zz);
		if (z == 'y') break;
	}
	return n;
}
/*行列の出力*/
void print_matrix(double a[N][N], int n) {
	int i, j;
	for (i = 1; i <= n; i ++) {
		for (j = 1; j <= n; j ++) {
			printf("%10.6lf", a[i][j]);
		}
		printf("\n");
	}
} 

#endif
