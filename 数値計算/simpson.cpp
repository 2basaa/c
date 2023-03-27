#include <stdio.h>
#include <math.h>

#define FNF(x) (1.0 - x)* exp(-x)

int main(){
	int i, n;
	double a,b,h,s;
	char z, zz;
	//printf("%lf\n", FNF(-0.8));
	while(1) {
		printf("シンプソン公式による積分計算\n\n");
		printf("f(x) = (1.0 -x) * exp(-x)\n\n");
		
		printf("積分区間[a,b]のa =");
		scanf("%lf%c", &a, &zz);
		
		printf("積分区間[a,b]のb =");
		scanf("%lf%c", &b, &zz);
		
		printf("分割数　　　　 n =");
		scanf("%d%c", &n, &zz);
		
		printf("\n\n正しく入力できましたか？ (y/n)");
		scanf("%c%c", &z, &zz);
		if(z == 'y') break;
	}
	h = (b-a) / n;
	printf("\nh %lf \n", h);
	s = FNF(a) + FNF(b);
	printf("\ns %lf \n", s);
	double se = 0.0;
	double so = 0.0;
	for(i=1; i <= n  -1; i ++) {
		double fnf_input = a + (i*h);
		double current = FNF(fnf_input);
		if(i % 2 == 0) {
			se += current;
			printf("\ns even %lf \n", se);
		}
		else {
			so += current;
			printf("\ns odd %lf \n", so);
		}
		printf("\nCurrent eval f(%lf) = %lf\n", fnf_input, current);
	}
	s = (s+ 2.0*se + 4.0 *so) * h /3.0;
	
	printf("積分の近似値 = %10.6lf\n", s);
	return 0;
}

