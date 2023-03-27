#include <stdio.h>
#include <math.h>

/*2分法とは、関数上の2つの値の中間値を求めていき、
解を求める方法となる。
*/
//f1(x)=x^4-3*x+1
double f1(double x) {
	return pow(x,4.0) - 3*x + 1;
}
//f2(x)=cos(x)-x
double f2(double x) {
	return cos(x) - x;
}
//f3(x)=e^x - (1/x)
double f3(double x) {
	//M_Eはe(=2.7...)
	return pow(M_E, x) - 1/x;
}

//f(x)=f3(x)
#define f(x)f3(x)
#define MAX_ITERATIONS 100

double bisection (double a, double b, double eps) {
	double c;//aとbの中間値
	int it = 0;
	/*
	do {
		実行される処理
	}while(条件式)
	*/
	do {
		c = (a + b) / 2.0;
		//f(a)<0 or f(c) < 0
		if (f(a) * f(c) < 0.0){
			b = c;
		}//f(a)*f(c)>=0
		else {
			a = c;
		}
		 it ++;
		 //fabsはfloat型絶対値
	}while (fabs(b - a) >= eps && it <= MAX_ITERATIONS);

	c = (a + b) / 2.0;
	printf("it = %d\n", it);//itは試行回数

	return c;//中間値
}

int main () {
	//a,bは中間地を求めるための初期値
	double a = 0.5;
	double b = 1.0;
	//epseilonはfabs(a-b)の条件式
	//epsilonは解を求める際の許容誤差
	double epsilon = 2e-30;
	double root = bisection(a,b,epsilon);
	
	printf("a?ｿｽ`b?ｿｽﾂ具ｿｽﾔの会ｿｽ?ｿｽ?ｿｽx=%f , f(x) = %g\n", root, f(root));
	return 0;
}