#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return pow(y, 2) - 2 * x*y - 6 * y + 2 * pow(x, 2) + 12;
}

double fdx(double x, double y) {
	return -2 * y + 4 * x;
}

double fdy(double x, double y) {
	return 2 * y - 2 * x - 6;
}

int main() {
	double x = 1, y = 1, h = 1, xn, yn;

	int it = 0;

	do {
		xn = x - h*fdx(x, y);
		yn = y - h*fdy(x, y);

		if (f(xn, yn) < f(x, y)) {
			x = xn;
			y = yn;
			h *= 2;
		}
		else //nao efetivar passo
			h /= 2;

		it++;

	} while (it < 10);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	cin.get();
	return 0;
}
