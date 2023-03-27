#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*�֐�*/
double f1(double x) {
	return pow(x, 4.0) -3*x +1;
}
double f2(double x) {
	return cos(x) -x;
}
double f3(double x) {
	return pow(M_E, x) -1/x;
}
double f4(double x) {
	return (pow(x, 3.0) -pow(x, 2.0)*3.0 + 9.0*x -8.0);
}
double f5(double x) {
	return (pow(x, 5.0) -sin(pow(x, 2.0))*20.0 + 3.0*x -11.0);
}
double f6(double x) {
	return (pow(x, 7.0) +pow(x, 5.0)*3.0 - pow(x,4.0)*9.0 -8.0* x);
}
double f7(double x) {
	return (pow(x, 3.0) -sin(x)*9.0 + cos(x)*2.0 -9.0);
}


/*�֐��ݒ�*/
#define f(x) f4(x)

/*����*/
/*���S����*/
double central_df(double x, double h) {
	return (f(x+h) - f(x-h))/(2.0*h);
	
}
/*�O�i����*/
double forward_df(double x, double h) {
	return (f(x+h) - f(x))/h;
	
}
/*��ލ���*/
double backward_df(double x, double h) {
	return (f(x) - f(x-h))/h;
	
}

/*�����̐ݒ�*/
#define EPSILON 0.0000001
#define df(x) central_df(x, EPSILON)/*���S����*/
//#define df(x) forward_df(x, EPSILON)/*�O�i����*/
//#define df(x) backward_df(x, EPSILON)/*��ލ���*/

/*�j���[�g���@*/
double newton (double np) {
	int i = 0;
	double xk = np, xk1;
	while(1) {
		i ++;
		xk1 = xk - f(xk) / df(xk) ;
		printf("Try %d Solution %.7f \n", i, xk1);
	if(fabs(xk1-xk) < EPSILON) {
		break;
	}
	xk = xk1;
	} 
	return xk;
}
/*main�֐�*/
int main(int argc, char ** argv) {
	double initial_value= 2.0;
	printf("d f(%.6f) = %lf \n", initial_value, df(initial_value));
	
	double sol = newton(initial_value);
	printf("Final Solution f(%.6f) = %lf \n", sol, f(sol));
	return 0;
}
