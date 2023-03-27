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
	/*��Βl���ő�̕���T��*/
	for (k = i + 1;k <= n; k ++) {
		if (fabs(a[m][i]) < fabs(a[k][i])) {
			m = k;
		}
	} 
	//�ő�l�Ǝw�肵���s��ϊ�
	/*��m�s�Ƒ�i�s�̓���ւ�*/
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
	a[][N+1] is augmented matrix(�g��s��)(n,n+1)
	p is a[i][i] = 1
	q is a[k][i](i+1<=k<=n)
	j is col of value
	k is row of value
	*/
	double p, q;
	int i, j, k;
	/*�Ίp������艺��f���o���ď�O�p�b��̌`�ɕό`*/
	for (i = 1; i <= n; i ++) {
		//i��̒��ōő�l��T���āA�ő�l�ƂȂ�s��i�s�̒l��ϊ�
		irekae(a, i, n);
		p = a[i][i];
		//|p|<10^(-6) process break
		if(fabs(p) < 1.0e-6) {
			printf("��Ӊ��������Ȃ�\n");
			return -1;
		}
	/*��i�s��(i,i)�����Ŋ���*/
		for(j = i; j <= n+1; j ++) {
			a[i][j] = a[i][j] / p;
		}
		//a[i+1]=0(i+1�s�ȍ~)���쐬
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
	/*�t�i����ɂ��v�Z*/
	for (i = n; i >= 1; i--) {
		s = 0.0;
		for (j = i+1; j<= n; j ++) {
			s += a[i][j] * x[j];
		}
		//x�̒l�𓾂�
		/*a[i][n+1]�͉�b[i]�ƂȂ�
		  x[i]=b[i]-s
		  x[n]=b[n]
		  x[n-j]=b[n-j]-��(n-j+1<=k<=n)a[n-j][k]*x[k]*/
		x[i] = a[i][n+1] - s;
	}
}

/*�s��̓���*/
int input_matrix(double a[N][N]) {
	int n, i, j;
	char z, zz;
	while(1) {
		printf("�s��̎����̓���(1 < n < %d) n =", N - 1);
		//z��zz��get
		scanf("%d%c", &n, &zz);
		if((n <= 1) || (N-1 <= n)) continue;
		printf("\n�s��A�̐��������\n\n");
		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= n; j ++) {
				printf("a(%d, %d)=", i, j);
				scanf("%lf%c", &a[i][j], &zz);
			}
			printf("\n");
		}
		printf("���������͂��܂������H(y/n)");
		scanf("%c%c", &z, &zz);
		if (z == 'y') break;
	}
	return n;
}
/*�s��̏o��*/
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
