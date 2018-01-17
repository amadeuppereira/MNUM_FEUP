#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double f1(double x, double y) {
	return x + y - 3;
}

double f2(double x, double y) {
	return x*x + y*y - 9;
}

double f1x(double x, double y) {
	return 1;
}

double f1y(double x, double y) {
	return 1;
}

double f2x(double x, double y) {
	return 2*x;
}

double f2y(double x, double y) {
	return 2 * y;
}

int main() {

	cout << fixed << setprecision(12);
	double xn = 4, yn = 1, tempx, tempy;
	do {
		tempx = xn;
		tempy = yn;
		xn = xn - (f1(xn, yn)*f2y(xn, yn) - f2(xn, yn)*f1y(xn, yn)) / (f1x(xn, yn)*f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn));
		yn = yn - (f2(xn, yn)*f1x(xn, yn) - f1(xn, yn)*f2x(xn, yn)) / (f1x(xn, yn)*f2y(xn, yn) - f2x(xn, yn)*f1y(xn, yn));

	} while ((abs(xn - tempx) / xn) > 0.00005 || (abs(yn - tempy) / yn) > 0.00005);

	cout << "x: " << xn << endl;
	cout << "y: " << yn << endl;

	cin.get();
	return 0;
}


