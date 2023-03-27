#include <stdio.h>

double avg(double, double); //関数avgのプロトタイプ宣言

void main () {
	double d1, d2, d3;
	double a = 1.2, b = 3.4, c = 2.7;
	d1 = avg(a,b);
	d2 = avg(4.1, 5.7);
	d3 = avg(c, 2.8);
	printf("d1 = %f, d2 = %f, d3 = %f\n", d1, d2, d3);	
} 

//平均値を求める関数
double avg(double i, double j) {
	double average = (i + j) / 2;
	return average;
} 
