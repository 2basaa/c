#include <stdio.h>
int main() {
	double a, b, c, d;
	a = 1.0 / 0.0; 
	b = -1.0 / 0.0;
	printf("a=%f b =%f\n", a, b);
	c = 1.0 / a;
	d = 1.0 / b;
	printf("c=%f d =%f\n", c, d);
	return 0;
}
