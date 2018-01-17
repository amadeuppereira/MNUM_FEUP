#include <iostream>
#include <math.h>
using namespace std;


// sistema de equacoes lineares

double f1(float x1, float x2, float x3) {
	return 7 - 3 * x1 - x2 - x3;
}

double f2(float x1, float x2, float x3) {
	return 4 - x1 - 4 * x2 - 2 * x3;
}

double f3(float x1, float x2, float x3) {
	return 5 - 2 * x2 - 5 * x3;
}

// formulas de recorrencia

double a(float x2, float x3) {
	return (7 - x2 - x3) / 3;
}

double b(float x1, float x3) {
	return (4 - x1 - 2 * 2 * x3) / 4;
}

double c(float x1, float x2) {
	return (5 - 2 * x2) / 5;
}


void gauss_jacobi() {
	//valores iniciais
	float x1 = 0, x2 = 0, x3 = 0;

	float temp1, temp2, temp3;
	cout << "0 | x1 = " << x1 << "      x2 = " << x2 << "       x3 = " << x3 << endl << endl;

	int it = 1;
	do {
		temp1 = x1, temp2 = x2, temp3 = x3;
		x1 = a(temp2, temp3);
		x2 = b(temp1, temp3);
		x3 = c(temp1, temp2);

		cout << it++ << " | x1 = " << x1 << "      x2 = " << x2 << "       x3 = " << x3 << endl;
		cout << "Rx1 = " << f1(x1, x2, x3) << "      Rx2 = " << f2(x1, x2, x3) << "      Rx3 = " << f3(x1, x2, x3) << endl << endl;

	} while ((abs(x1 - temp1) > 0.00005) && (abs(x2 - temp2) > 0.00005) && (abs(x3 - temp3) > 0.00005));
}

void gauss_seidel() {
	//valores iniciais
	float x1 = 0, x2 = 0, x3 = 0;

	float temp1, temp2, temp3;
	cout << "0 | x1 = " << x1 << "      x2 = " << x2 << "       x3 = " << x3 << endl << endl;

	int it = 1;
	do {
		temp1 = x1, temp2 = x2, temp3 = x3;
		x1 = a(x2, x3);
		x2 = b(x1, x3);
		x3 = c(x1, x2);

		cout << it++ << " | x1 = " << x1 << "      x2 = " << x2 << "       x3 = " << x3 << endl;
		cout << "Rx1 = " << f1(x1, x2, x3) << "      Rx2 = " << f2(x1, x2, x3) << "      Rx3 = " << f3(x1, x2, x3) << endl << endl;

	} while ((abs(x1 - temp1) > 0.00005) && (abs(x2 - temp2) > 0.00005) && (abs(x3 - temp3) > 0.00005));
}

int main() {

	cout << "-- Gauss-Jacobi --\n\n";
	gauss_jacobi();

	cout << "-- Gauss-Seidel --\n\n";
	gauss_seidel();

	cin.get();
	return 0;
}