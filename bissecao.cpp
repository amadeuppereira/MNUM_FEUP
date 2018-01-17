#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f(double x) {
	return (0.646*x - 1) / (x - 1);
}

int main() {

	cout << fixed << setprecision(10);

	double a = 1.3, b = 1.8, xn;
	int cnt = 0;

	do {
		xn = (a + b) / 2;

		cout << ++cnt << " | a: " << a << " f(a): " << f(a) << " | b:  " << b << " f(b): " << f(b) << " | xn: " << xn << " f(xn): " << f(xn) << endl;

		if ((f(a)*f(xn)) < 0) {
			b = xn;
		}
		else
			a = xn;
	} while (cnt < 20);
	


	cin.get();
	return 0;
}