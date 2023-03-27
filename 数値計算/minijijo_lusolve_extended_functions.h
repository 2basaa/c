
/*基本関数の関数値を求める*/
double ffv(int fi, double x)
{
    double y;
    switch(fi) {
        case 1: y = 1.0;     break;
        case 2: y = x;       break;
        case 3: y = pow(x,2);     break;
        case 4: y = pow(x,3);   break;
        case 5: y = pow(x,4);   break;
        case 6: y = pow(x,5);   break;
        case 7: y = pow(x,6);   break;
        case 8: y = pow(x,7);   break;
        case 9: y = pow(x,8);   break;
        case 10: y = pow(x,9);   break;
        case 11: y = pow(x,10);   break;
        case 12: y = 1.0/x;   break;
        case 13: y = exp(x);  break;

        default: y = x;      break;
    }
    return y;
}

/*　モデルを読み取る　*/
int read_model(FILE *fp_models, int f_id[N])
{
    int j, k;
    /* 基本関数の数を読み取る */;
    fscanf(fp_models, "%d", &k);
    /* 基本関数fk(x)を１〜kの番号を読み取る */
    for (j=1; j <= k; j++) {
        /* f(x)= [1:定数, 2:x, 3:x*x, 4:x*x*x, 5:1/x, 6:e^x, ] */
        fscanf(fp_models, "%d", &(f_id[j]));
    }
    return k;
}

/*** データの入力 ***/
int data_input(char *fname, double x[N], double y[N] )
{
    int n=-1, i;
    FILE* fp;
    
    fp = fopen(fname,"r");
    if (fp == NULL){
        printf("ファイル「%s」を開くことができません", fname);
        exit(0);
    }
    /* データの個数は何個ですか？（1< n < %d）n = ", N); */
    fscanf(fp,"%d", &n);
    if ( (n <= 1) || (N <= n) )
        printf("データの個数は(1< n < %d）でなければなりません, n = %d", N, n);
    
    /* printf("\nデータxの値は小から大の順に入力する. \n"); */
    for(i=1; i<=n; i++) {
        fscanf(fp,"%lf", &x[i]);
        fscanf(fp,"%lf", &y[i]);
    }
    
    fclose(fp);
    return n;
}

/* Aとbを設定する */
void set_A_tA_b(int n, int k, int f_id[N], double x[N], double y[N], double A[N][N], double tA[N][N], double b[N])
{
    int i, j;
    /*** 関数を呼び出しAを設定する ***/
    for(i=1; i<=n; i++) {
        for (j=1; j<= k; j++) {
            A[i][j] = ffv(f_id[j], x[i]);
            tA[j][i] = A[i][j];
        }
        /*** bを設定する ***/
        b[i] = y[i];
    }
}

/* tA[k][n]・A[n][k]を計算して配列tAA[k][k]に入れる */
void seki_tA_A(int n, int k, double tA[N][N], double A[N][N], double tAA[N][N])
{
    int i, j, jj;
    double s;
    
    for(jj=1; jj <= k; jj++) {
        for(j=1; j<=k; j++) {
            s = 0.0;
            for(i=1; i<=n; i++) {
                s = s + tA[jj][i] * A[i][j];
            }
            tAA[jj][j] = s;
        }
    }
}

/* tA[k][n]・b[k][1]を計算してtAb[k][1]配列に入れる */
void seki_tA_b(int n, int k, double tA[N][N], double b[N], double tAb[N])
{
    double s;
    int i, j;
    tAb[0]=0;
    for(j=1; j <= k; j++) {
        s= 0.0;
        for(i=1; i<=n; i++) {
            s = s + tA[j][i] * b[i];
        }
        tAb[j] = s;
    }
}

/*　グラフを描くための準備 (数表を出力) */
void data_output(char *fname, int n, int k, double x[N], double y[N], double sol[N], int f_id[N])
{
    double h, xx, yy;
    int i, j;
    FILE* fp;
    
    fp = fopen(fname,"w");
    if (fp == NULL){
        printf("ファイル「%s」を開くことができません", fname);
        exit(0);
    }

    
    h = (x[n] - x[1]) / 500.0;
    xx = x[1] ;
    for(i=0; i<=500; i++) {
        yy = 0.0;
        for (j=1; j<= k; j++)
            yy += sol[j] * ffv(f_id[j], xx) ;
        fprintf(fp, "%lf\t%lf\n", xx, yy);
        xx = xx + h;
    }
    fclose(fp);
}

/* 誤差を求める　*/
double error(int n, int k , double x[N], double y[N], double sol[N], int f_id[N])
{
    int i, j;
    double err =0.0, yy;
    
    for (i=1; i <= n; i++){
        yy = 0.0;
        for (j=1; j<= k; j++){
            yy += sol[j] * ffv(f_id[j], x[i]);
        }
        err += (yy-y[i])*(yy-y[i]);
    }
    return err/n;
}

