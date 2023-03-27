double f(double x,double y, double z) {
	return (-1.0 - x + x*x - y + y*y + x*z);
}

double g(double x, double y, double z) {
	return (-4.0 + 3.0*x*x + x*x*x - 2.0*z + 2.0*y*z - z*z + z*z*z);
}

double h(double x, double y, double z) {
	return (-2.0*x -3.0*y + 3.0*x*y - 4.0*z + 2.0*x*z + 4.0*y*z);
}

/*f�֐��̕Δ���*/
double f_x(double x, double y, double z) {
	return (-1.0 + 2.0*x + z);
}

double f_y(double x, double y, double z) {
	return (-1.0 + 2.0*y);
}

double f_z(double x, double y ,double z) {
	return (x);
}

/*g�֐��̕Δ���*/
double g_x(double x, double y, double z) {
	return(6.0*x + 3.0*x*x);
}

double g_y(double x, double y, double z) {
	return (2.0*z);
}

double g_z(double x, double y ,double z) {
	return (-2.0 + 2.0*y - 2.0*z + 3.0*z*z);
}

/*h�֐��̕Δ���*/
double h_x(double x, double y, double z) {
	return(-2.0 + 3.0*y + 2.0*z);
}

double h_y(double x, double y, double z) {
	return (-3.0 + 3.0*x + 4.0*z);
}

double h_z(double x, double y ,double z) {
	return (-4.0 + 2.0*x + 4.0*y);
}
