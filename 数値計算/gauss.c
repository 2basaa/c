#include <stdio.h>
#include <math.h>

#define N 10

#include "my_library.h"

int main (void) {
	int n, i, j;
	//a is argumented matrix(拡大行列)(n,n+1)
	//a[][N+1] is solution
	static double a[N][N + 1], x[N] ;
	char z, zz;
	
	while(1) {
		printf("ガウスの消去による連立方程式の解法\n");
		printf("南元連立方程式ですか(1 < n < 9) n = ");
		scanf("%d%c", &n, &zz);
		if ((n <= 1) || (N -1 <= n)) continue;
		printf("\n係数を入力してください\n\n");
		//拡大行列(n,n+1)を作成
		for (i = 1; i <= n +1; i ++) {
			for (j = 1; j <= n + 1; j ++) {
				printf("a(%d, %d)=", i, j);
				scanf("%lf%c", &a[i][j], &zz);
			}	
			printf("\n");
		}
		printf("正しく入力出来ましたか?(y/n)");
		//yかnの入力
		scanf("%c%c", &z,&zz);
		if(z == 'y') break;	
	}
	
	//ガウスの消去法を実行
	int ret = gaussian_elimination(a,n);
	if (ret != 0) {
		return ret;
	}
	//逆進代入を行い、解x[i]を求める
	inverse_substitution(a, x, n);
	
	/*解の表示*/
	printf("\n連立方程式の解\n\n");
	for(i = 1; i<= n; i ++) {
		printf("x(%d) = %10.61f\n", i , x[i]);
	} 
	return 0;
}
