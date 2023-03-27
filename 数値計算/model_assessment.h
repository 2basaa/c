double get_model(double x[N], double y[N],
int f_id[N], double sol[N], int n, int k)
{
	double A[N][N], tA[N][N], b[N], tAA[N][N], tAb[N];
	double err;
	int i;
	
	for(i=0; i<=k; i++) {
		sol[i] = 0;
	}
	
	/*A��b��ݒ肷��B*/
	set_A_tA_b(n, k, f_id, x, y, A, tA, b);
	/*tA[k][n]*A[n][k]���v�Z���Ĕz��tAA[k][k]�ɓ����*/
	seki_tA_A(n, k, tA, A, tAA);
	/*tA[k][n]*b[k][1]���v�Z���Ĕz��tAb[k][1]�ɓ����*/
	seki_tA_b(n, k, tA, b, tAb);
	/*LU�����ŉ���*/
	lu_solve(k, tAA, tAb, sol);
	/*�덷�����߂�B*/
	err = error(n, k, x, y, sol, f_id);
	
	return err;
}
