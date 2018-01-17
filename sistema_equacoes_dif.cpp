#include <iostream>
#include <math.h>
using namespace std;
/*
     AINDA POR TESTAR
	------------------
*/

//sistema de equacoes
float f(float x, float y, float z) {
	return z*y + x;
}

float g(float x, float y, float z) {
	return z*x + y;
}

void euler() {
	//intervalo
	float a = 0, b = 0.499;

	//valores iniciais
	float x = 0, y = 1, z = 1, h = 0.1;

	while (x <= b) {
		float yTemp = y;
		y = y + h*f(x, y, z);
		z = z + h*g(x, yTemp, z);
		x = x + h;
	}

	cout << "y: " << y << endl;
	cout << "z: " << z << endl;

	x = 0;
	float y1 = 1;
	float z1 = 1;
	h = h / 2;

	while (x <= b) {
		float yTemp = y1;
		y1 = y1 + h*f(x, y1, z1);
		z1 = z1 + h*g(x, yTemp, z1);
		x = x + h;
	}

	cout << "y1: " << y1 << endl;
	cout << "z1: " << z1 << endl;

	x = 0;
	float y2 = 1;
	float z2 = 1;
	h = h / 2;

	while (x <= b) {
		float yTemp = y2;
		y2 = y2 + h*f(x, y2, z2);
		z2 = z2 + h*g(x, yTemp, z2);
		x = x + h;
	}

	cout << "y2: " << y2 << endl;
	cout << "z2: " << z2 << endl << endl;

	//qc tem que ser aproximadamente 2, se nao dividir h por 2 e fazer outra vez
	cout << "QC y = " << (y1 - y) / (y2 - y1) << endl;
	cout << "QC z = " << (z1 - z) / (z2 - z1) << endl << endl;

	cout << "E y = " << y2 - y1 << endl;
	cout << "E z = " << z2 - z1 << endl;
}

void rk4() {

	//intervalo
	float a = 0, b = 0.499;

	//valores iniciais
	float x = 0, y = 1, z = 1, h = 0.1;

	while (x <= b) {
		double dy1 = h*f(x, y, z);
		double dz1 = h*g(x, y, z);
		double dy2 = h*f(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dz2 = h*g(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dy3 = h*f(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dz3 = h*g(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dy4 = h*f(x + h, y + dy3, z + dz3);
		double dz4 = h*g(x + h, y + dy3, z + dz3);

		float yTemp = y;
		y = y + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z = z + dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		x = x + h;
	}

	float y1 = y;
	float z1 = z;

	cout << "y: " << y1 << endl;
	cout << "z: " << z1 << endl;

	x = 0;
	y = 1;
	z = 1;
	h = h / 2;

	while (x <= b) {
		double dy1 = h*f(x, y, z);
		double dz1 = h*g(x, y, z);
		double dy2 = h*f(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dz2 = h*g(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dy3 = h*f(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dz3 = h*g(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dy4 = h*f(x + h, y + dy3, z + dz3);
		double dz4 = h*g(x + h, y + dy3, z + dz3);

		float yTemp = y;
		y = y + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z = z + dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		x = x + h;
	}

	float y2 = y;
	float z2 = z;

	cout << "y1: " << y2 << endl;
	cout << "z1: " << z2 << endl;

	x = 0;
	y = 1;
	z = 1;
	h = h / 2;

	while (x <= b) {
		double dy1 = h*f(x, y, z);
		double dz1 = h*g(x, y, z);
		double dy2 = h*f(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dz2 = h*g(x + h / 2, y + dy1 / 2, z + dz1 / 2);
		double dy3 = h*f(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dz3 = h*g(x + h / 2, y + dy2 / 2, z + dz2 / 2);
		double dy4 = h*f(x + h, y + dy3, z + dz3);
		double dz4 = h*g(x + h, y + dy3, z + dz3);

		float yTemp = y;
		y = y + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		z = z + dz1 / 6 + dz2 / 3 + dz3 / 3 + dz4 / 6;
		x = x + h;
	}

	float y3 = y;
	float z3 = z;

	cout << "y2: " << y3 << endl;
	cout << "z2: " << z3 << endl << endl;

	//tem que ser aprox 16, se nao h/2 e fazer outra vez
	cout << "QC y = " << (y2 - y1) / (y3 - y2) << endl;
	cout << "QC z = " << (z2 - z1) / (z3 - z2) << endl << endl;

	cout << "E y = " << (y3 - y2) / 15 << endl;
	cout << "E z = " << (z3 - z2) / 15 << endl;
}

int main() {

	cout << "-- Euler --\n\n";
	euler();

	cout << "\n-- RK4 --\n\n";
	rk4();

	cin.get();
	return 0;
}