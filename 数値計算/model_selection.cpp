#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define N 220
#include "my_library_v3.h"
#include "minijijo_lusolve_extended_functions.h"
#include "model_assessment.h"

enum result {TRUE, FALSE};

int f_in_model(int f_id[N], int fi, int k)
{
    int i;
    int in_model = FALSE;
    
    for (i =1; i<= k; i++)
    {
        if (fi == f_id[i])
        {
            in_model = TRUE;
            break;
        }
    }
    return in_model;        
}

double forward_step_wise_selection(int nf, double x_train[N], double y_train[N], double x_test[N], double y_test[N], int best_f_id[N], double best_sol[N], int n_train, int n_test, int*  best_k, char* path)
{
    int f_id[N]={0}; /*基本関数のid*/
    double sol[N];
    int i, k, j;
    double err, best_err_train = DBL_MAX; /* <float.h> */
    double best_err_test =0.0;
    char out_fname[200];
    char error_fname[200];
        
    sprintf(error_fname,"%s%s", path, "best_model_error.txt");
    
    FILE* fp = fopen(error_fname,"w");
    if (fp == NULL){
        printf("ファイル「%s」を開くことができません", "best_model_error.txt");
        exit(0);
    }

    for (k=1; k <= nf; k++)     /* k basic functions */
    {
        printf("--- k = %d ---\n", k);
        for (j=1; j <= k; j++)
        {
            f_id[j] = best_f_id[j];
        }

        for (i=1; i<=nf; i++)
        {
            if (f_in_model(f_id, i, k-1) == FALSE)
            {
                f_id[k] = i;
                get_model(x_train, y_train, f_id, sol, n_train, k);
                /* 誤差を求める　*/
                err = error(n_train, k , x_train, y_train, sol, f_id);
                
                /* Update model */
                if (err < best_err_train)
                {
                    best_err_train = err;
                    (*best_k) = k;
                    for (j=1; j <= k; j++)
                    {
                        best_f_id[j] = f_id[j];
                        best_sol[j] = sol[j];
                    }
                }
                    
                /*　誤差と求めた基本関数の係数を出力 */
                printf("%d %f　", i, err);
                for (j=1; j<=k; j++) {
                    printf("%.7f*f%d ",sol[j],f_id[j]);
                }
                printf("\n");
            }

        }        
        printf("k=%d 最高のモデル\n", (*best_k));
        printf(" 誤差:  %f\n", best_err_train);
        printf(" モデル: ");
        for (j=1; j <= (*best_k); j++) {
            printf("%.7f*f%d ",best_sol[j],best_f_id[j]);
        }
        printf("\n");
        
        /* 誤差を求める　*/
        best_err_test = error(n_test, (*best_k) , x_test, y_test, best_sol, best_f_id);
        
        fprintf(fp,"%f %f\n", best_err_train, best_err_test);

        /*　グラフを描くための準備 (数表を出力) */
       sprintf(out_fname,"%smk%d_est", path, (*best_k));
       data_output(out_fname, n_train, (*best_k), x_train, y_train, best_sol, best_f_id);        
    }

    fclose(fp);
    return best_err_train;
}

int main(void)
{
    
    int nf = 13; /* 基本関数の数*/
    int n_train, n_test;  /* n個データ点数,  */
    double x_train[N], y_train[N];
    double x_test[N], y_test[N];
    double best_sol[N] = {0}; /* 最高のモデルの求めたa1,...akの係数*/
    int best_k, best_f_id[N]; /* 最高のモデル：基本関数の数k、基本関数のid　 */
    double best_err; /* 最高のモデルの誤差*/

    char *data_train="data_train.txt";
    char *data_test="data_test.txt";

    char *path= "/Users/Tsubasa/OneDrive/デスクトップ/データ/";
    char data_train_fname[200];
    char data_test_fname[200];
    sprintf(data_train_fname,"%s%s", path, data_train);
    sprintf(data_test_fname, "%s%s", path, data_test);

    printf("このプログラムは最小2乗法によって　\n");
    printf("y = a1*f1(x) + a2*f2(x) +...+ ak*fk(x) \n");
    printf("の形の曲線をあてはめるものです．\n\n");
    printf("\n求めた誤差と基本関数の係数の出力\n");

    /*** データの入力 ***/
    n_train = data_input(data_train_fname, x_train, y_train);
    n_test = data_input(data_test_fname, x_test, y_test);
    
    best_err = forward_step_wise_selection(nf, x_train, y_train, x_test, y_test, best_f_id, best_sol, n_train, n_test, &best_k, path);

}
