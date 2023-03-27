double get_model(double x[N], double y[N],
int f_id[N], double sol[N], int n, int k)
{
	double A[N][N], tA[N][N], b[N], tAA[N][N], tAb[N];
	double err;
	int i;
	
	for(i=0; i<=k; i++) {
		sol[i] = 0;
	}
	
	/*Aとbを設定する。*/
	set_A_tA_b(n, k, f_id, x, y, A, tA, b);
	/*tA[k][n]*A[n][k]を計算して配列tAA[k][k]に入れる*/
	seki_tA_A(n, k, tA, A, tAA);
	/*tA[k][n]*b[k][1]を計算して配列tAb[k][1]に入れる*/
	seki_tA_b(n, k, tA, b, tAb);
	/*LU分解で解く*/
	lu_solve(k, tAA, tAb, sol);
	/*誤差を求める。*/
	err = error(n, k, x, y, sol, f_id);
	
	return err;
}
