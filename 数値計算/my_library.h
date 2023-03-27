/*
#ifndef
#endif
上で、1回だけコンパイル
*/
#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//irekae() is swap(row of i row of m)
//0行、0列は無視している
void irekae(double a[][N+1], int i, int n) {
	/*
	m is row
	j is col
	k(i+1<=k<=n) change row
	*/
	int m, j, k;
	//key is value of swap 
	double key;
	m = i;//m is row of i
	for (k = i+ 1; k <= n; k ++) {
		//|a[m][i]|<|a[k][i]|m=k
		if (fabs(a[m][i]) < fabs(a[k][i])){
			m = k;
		}
	}	
	//swap row of m and row of i
	for (j = 1; j <= n + 1; j ++) {
		key = a[m][j];
		a[m][j] = a[i][j];
		a[i][j] = key;
	} 
}

//makes matrix"a" upper triangular by Gaussian eliminataion
// n is the number of rows

//executive gauss_eliminate
//上三角型連立方程式を作成
//前進消去という
int gaussian_elimination(double a[][N + 1], int n) {
	/*
	a[][N+1] is augmented matrix(拡大行列)(n,n+1)
	p is a[i][i] = 1
	q is a[k][i](i+1<=k<=n)
	j is col of value
	k is row of value
	*/
	double p, q;
	int i, j, k;
	//swap row of i
	for ( i = 1; i <= n; i ++) {
		irekae(a,i,n);//(1<=i<=n) swap
		p = a[i][i];
		//|p|<10^(-6) break
		if(fabs(p) < 1.0e-6) {
			printf("一意解は存在しない\n");
			return -1;
		}
		/*change value of col
		a[i][i]=1, a[i][j] /= a[i][i]*/
		for (j = i;j <= n + 1; j ++) {
			a[i][j] = a[i][j] / p;	
		}  
		/* change (i+1<=k<=n)a[k][j]=0*/
		//下記を繰り返し、実行することによって、
		//a[i+1]=0(i+1行以降)とする
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
		//n*nの行列
		//s+=a[i][j]*x[j]の行列の解とする
		//x[1],x[2],...,x[n]を求めるための値を出す
		for (j = i + 1; j <= n; j ++){
			s += a[i][j] * x[j];
		}
		/*a[i][n+1]は解b[i]となる
		  x[i]=b[i]-s
		  x[n]=b[n]
		  x[n-j]=b[n-j]-Σ(n-j+1<=k<=n)a[n-j][k]*x[k]*/
		x[i] = a[i][n+1] - s;
	}	
}
#endif

