#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20
#include "my_library_v3.h"
#include "minijijo_lusolve_extended_functions.h"

int main(void) {
	int n,k,m; /*n�f�[�^�_���Ak��{�֐��A�����f��*/
	int i, j;/*�s�Ɨ�̃C���f�b�N�X*/
	int f_id[N];
	double x[N], y[N],A[N][N], tA[N][N], b[N], tAA[N][N], tAb[N];
	double sol[N] = {0};/*���߂�a1,...ak�̌W��������*/
	double err;
	char *models = "models.txt";
	char *data = "bb_age_length.txt";
	//char *data = "nh_covid_italy.txt;
	//char *data = "nh_bb_age_weigth.txt;
	//char *data = "nh_bb_age_length.txt;
	//char *data = "nh_fish.txt;
	//char *data = "nh_wine.txt;
	char *path = "/Users/Tsubasa/OneDrive/�f�X�N�g�b�v/�f�[�^/";
	char data_fname[200], out_fname[200], models_fname[200];
	FILE *fp_models;
	
	sprintf(data_fname,"%s%s", path, data);
	sprintf(models_fname,"%s%s", path, models);
	
	fp_models = fopen(models_fname, "r");
	fscanf(fp_models,"%d", &m);
	
	printf("���̃v���O�����͍ŏ�2��@�ɂ���� \n");
	printf("y = a1*f1(x)+ a2*f2(x) + ... + ak*fk(x) \n");
	printf("�̌`�̋Ȑ������Ă͂߂���̂ł� \n\n");
	printf("\n ���߂��덷�Ɗ�{�֐��̌W�����o�� \n");
	
	/*�f�[�^�̓���*/
	n = data_input(data_fname, x, y);
	
	for (i = 1; i<=m; i++) {
		/*��{�֐��̐�k�Ɗ�{�֐�fk(x)��1�`k�̔ԍ���ǂݎ��*/
		k = read_model(fp_models, f_id);
		/*A��b��ݒ肷��*/
		set_A_tA_b(n, k, f_id, x, y, A, tA, b);
		/*tA[k][n]*A[n][k]���v�Z���Ĕz��tAA[k][k]�ɓ����*/
		seki_tA_A(n, k, tA, A, tAA); 
		/*tA[k][n]*b[k][1]���v�Z���Ĕz��tAb[k][1]�ɓ����*/
		seki_tA_b(n, k, tA, b, tAb);
		/*LU����@�ŉ���*/
		lu_solve(k, tAA, tAb, sol);
		 /*�덷�����߂�*/
		err = error(n, k, x, y, sol, f_id);
		
		/*�덷�Ƌ��߂���{�֐��̌W�����o��*/
		printf("%f ", err);
		for(j=1; j<= k; j++) {
			printf("%f*f%d ", sol[j], f_id[j]);
		} 
		printf("\n");
		
		/*���\�̏o��*/
		sprintf(out_fname, "%sm%d_est_%s", path, i, data);
		data_output(out_fname, n, k, x, y, sol, f_id);
	}
	fclose(fp_models);
}
