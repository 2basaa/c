#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//f1(x)=x^4-3*x+1
double f1(double x) {
	return pow(x,4.0) -3*x + 1 ;
}
//f1_prime(x)=(4x)^3-3*x+1
double f1_prime(double x) {
	return 4*pow(x,3.0) -3*x + 1 ;
}
//f2(x)=cos(x)-x
double f2(double x) {
	return cos(x) - x;
}
//f2_prime(x)=-sin(x)-1
double f2_prime(double x) {
	return -sin(x) - 1;
}
//f3(x)=e^x-(1/x)
double f3(double x) {
	return pow(M_E, x) -1/x;
}
//f3_prime(x)=e^x+(1/x^2)
double f3_prime(double x) {
	return pow(M_E, x) + 1/pow(x,2);
}
//f4(x)=(x^3-3*x^2+9x-8)
double f4(double x) {
	return (pow(x,3.0) -pow(x,2.0)*3.0 +9.0*x-8.0);
}
//f4_prime(x)=(3*x^2-6*x+9)
double f4_prime(double x) {
	return (3.0*pow(x,2.0)-6.0*x+9.0);
}
#define f(x)f4(x)
#define f_prime(x)f4_prime(x)
#define EPSILON 0.000001
 
 //�j���[�g���@
double newton (double np) {
	int i = 0;//i�͎��s��
	//xk=np&double xk1
	double xk = np, xk1;
	while(1) {
		i ++;
		//�j���[�g���Q���������s
		//xk1=xk-f(xk)/f'(xk)
		xk1 = xk - f(xk) / f_prime(xk) ;
		printf("Try %d Solution %.7f \n", i, xk1);
		//|xk1-xk|<EPSILON�Ȃ�Awhile�������I��
		if(fabs(xk1-xk) < EPSILON) {
			break;
		}
		xk = xk1;//xk��xk1�Ƃ���
	}
	printf ("Try_count = %d\n", i);//�ŏI���s�񐔂��킩��R�[�h 
	return xk;//���s�񐔂𓾂�
}

//**(�_�u���|�C���^)
/*�_�u���|�C���^���g���̂́A�֐����̃|�C���^��
�i�[����Ă���A�h���X��ύX����Ƃ��Ɏg�p

argc�̓R�}���h���C�������̐�������z��
argv�̓R�}���h���C���������i�[
*/

int main(int argc, char ** argv) {
	double initial_value= 0.0;
		printf("Final Solution %.6f\n", newton(initial_value));
	return 0;
}