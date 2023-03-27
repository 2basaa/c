#include <stdio.h>
#include <math.h>

/*2���@�Ƃ́A�֐����2�̒l�̒��Ԓl�����߂Ă����A
�������߂���@�ƂȂ�B
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
	//M_E��e(=2.7...)
	return pow(M_E, x) - 1/x;
}

//f(x)=f3(x)
#define f(x)f3(x)
#define MAX_ITERATIONS 100

double bisection (double a, double b, double eps) {
	double c;//a��b�̒��Ԓl
	int it = 0;
	/*
	do {
		���s����鏈��
	}while(������)
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
		 //fabs��float�^��Βl
	}while (fabs(b - a) >= eps && it <= MAX_ITERATIONS);

	c = (a + b) / 2.0;
	printf("it = %d\n", it);//it�͎��s��

	return c;//���Ԓl
}

int main () {
	//a,b�͒��Ԓn�����߂邽�߂̏����l
	double a = 0.5;
	double b = 1.0;
	//epseilon��fabs(a-b)�̏�����
	//epsilon�͉������߂�ۂ̋��e�덷
	double epsilon = 2e-30;
	double root = bisection(a,b,epsilon);
	
	printf("a?��`b?���Ԃ̉�?��?��x=%f , f(x) = %g\n", root, f(root));
	return 0;
}