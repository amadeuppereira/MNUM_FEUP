#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

int main() {
	//intervalo em que se sabe estar o minimo
	double x1 = -1, x2 = 0, x3, x4;
	double B = (sqrt(5) - 1) / 2, A = pow(B, 2);

	do {
		x3 = x1 + A*(x2 - x1);
		x4 = x1 + B*(x2 - x1);

		//Para o calcular o máximo é só trocar o sinal < por >
		if (f(x3)<f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}

	} while (abs(x1 - x2) > 0.001);

	cout << "x: " << x1 << endl;


	cin.get();
	return 0;
}