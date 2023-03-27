#include <stdio.h>
int global = 10;

void func1(double, int);
void func2() ;
void main() {
	double a = 123.41;
	int b = 100;
	printf("main処理中:\n");
	printf("global = %d\n", global);
	printf("a = %f, b = %d\n", a, b);
	printf("*************\n");
	func1(3.1, 4);
	func2();
}

//func1
void func1(double a, int b) {
	printf("func1処理中\n");
	printf("global = %d\n", global);
	printf("a = %f, b = %d\n", a, b);
	printf("*************\n");
}

//func2
void func2 () {
	double a = - 4.1;
	int b = 2;//関数内でa,bのタイプを指定してもよい
	printf("global = %d\n", global);
	printf("a = %f, b = %d\n", a, b);
	printf("*************\n"); 
}
