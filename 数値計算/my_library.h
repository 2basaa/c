/*
#ifndef
#endif
��ŁA1�񂾂��R���p�C��
*/
#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//irekae() is swap(row of i row of m)
//0�s�A0��͖������Ă���
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
//��O�p�^�A�����������쐬
//�O�i�����Ƃ���
int gaussian_elimination(double a[][N + 1], int n) {
	/*
	a[][N+1] is augmented matrix(�g��s��)(n,n+1)
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
			printf("��Ӊ��͑��݂��Ȃ�\n");
			return -1;
		}
		/*change value of col
		a[i][i]=1, a[i][j] /= a[i][i]*/
		for (j = i;j <= n + 1; j ++) {
			a[i][j] = a[i][j] / p;	
		}  
		/* change (i+1<=k<=n)a[k][j]=0*/
		//���L���J��Ԃ��A���s���邱�Ƃɂ���āA
		//a[i+1]=0(i+1�s�ȍ~)�Ƃ���
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
	/*�t�i����ɂ��v�Z*/
	for (i = n; i>= 1; i--) {
		s = 0.0;
		//n*n�̍s��
		//s+=a[i][j]*x[j]�̍s��̉��Ƃ���
		//x[1],x[2],...,x[n]�����߂邽�߂̒l���o��
		for (j = i + 1; j <= n; j ++){
			s += a[i][j] * x[j];
		}
		/*a[i][n+1]�͉�b[i]�ƂȂ�
		  x[i]=b[i]-s
		  x[n]=b[n]
		  x[n-j]=b[n-j]-��(n-j+1<=k<=n)a[n-j][k]*x[k]*/
		x[i] = a[i][n+1] - s;
	}	
}
#endif

