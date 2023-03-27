#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20
#include "my_library_v3.h"
#include "minijijo_lusolve_extended_functions.h"

int main(void) {
	int n,k,m; /*n個データ点数、k基本関数、ｍモデル*/
	int i, j;/*行と列のインデックス*/
	int f_id[N];
	double x[N], y[N],A[N][N], tA[N][N], b[N], tAA[N][N], tAb[N];
	double sol[N] = {0};/*求めたa1,...akの係数を扱う*/
	double err;
	char *models = "models.txt";
	char *data = "bb_age_length.txt";
	//char *data = "nh_covid_italy.txt;
	//char *data = "nh_bb_age_weigth.txt;
	//char *data = "nh_bb_age_length.txt;
	//char *data = "nh_fish.txt;
	//char *data = "nh_wine.txt;
	char *path = "/Users/Tsubasa/OneDrive/デスクトップ/データ/";
	char data_fname[200], out_fname[200], models_fname[200];
	FILE *fp_models;
	
	sprintf(data_fname,"%s%s", path, data);
	sprintf(models_fname,"%s%s", path, models);
	
	fp_models = fopen(models_fname, "r");
	fscanf(fp_models,"%d", &m);
	
	printf("このプログラムは最小2乗法によって \n");
	printf("y = a1*f1(x)+ a2*f2(x) + ... + ak*fk(x) \n");
	printf("の形の曲線をあてはめるものです \n\n");
	printf("\n 求めた誤差と基本関数の係数を出力 \n");
	
	/*データの入力*/
	n = data_input(data_fname, x, y);
	
	for (i = 1; i<=m; i++) {
		/*基本関数の数kと基本関数fk(x)を1～kの番号を読み取る*/
		k = read_model(fp_models, f_id);
		/*Aとbを設定する*/
		set_A_tA_b(n, k, f_id, x, y, A, tA, b);
		/*tA[k][n]*A[n][k]を計算して配列tAA[k][k]に入れる*/
		seki_tA_A(n, k, tA, A, tAA); 
		/*tA[k][n]*b[k][1]を計算して配列tAb[k][1]に入れる*/
		seki_tA_b(n, k, tA, b, tAb);
		/*LU分解法で解く*/
		lu_solve(k, tAA, tAb, sol);
		 /*誤差を求める*/
		err = error(n, k, x, y, sol, f_id);
		
		/*誤差と求めた基本関数の係数を出力*/
		printf("%f ", err);
		for(j=1; j<= k; j++) {
			printf("%f*f%d ", sol[j], f_id[j]);
		} 
		printf("\n");
		
		/*数表の出力*/
		sprintf(out_fname, "%sm%d_est_%s", path, i, data);
		data_output(out_fname, n, k, x, y, sol, f_id);
	}
	fclose(fp_models);
}
