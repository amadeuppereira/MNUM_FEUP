#include <iostream>
#include <math.h>
using namespace std;

double f(float x, float y) {
	return pow(x, 2) + pow(y, 2);
}

void euler() {
	//intervalo de integracao
	float a = 0, b = 1.3999;

	//valores iniciais
	float x0 = 0, y0 = 0;

	float h = 0.1, h1 = h / 2, h2 = h1 / 2;
	float x = x0;
	float y = y0, y1 = y0, y2 = y0;

	//Calcular S com h
	while (x < b) {
		y = y + h*f(x, y);
		x = x + h;
	}

	cout << "y: " << y << endl;

	//Calcular S' com h' = h/2
	x = x0;
	while (x < b) {
		y1 = y1 + h1*f(x, y1);
		x = x + h;
	}

	cout << "y1: " << y1 << endl;

	//Calcular S'' com h'' = h'/2
	x = x0;
	while (x < b) {
		y2 = y2 + h2*f(x, y2);
		x = x + h;
	}

	cout << "y2: " << y2 << endl;

	// Qc tem que ser aproxidamente 2, se nao, dividir h/2 e fazer novamente
	cout << "QC = " << (y1 - y) / (y2 - y1) << endl;
	cout << "E = " << y2 - y1 << endl;
}

void rk2() {
	//intervalo de integracao
	float a = 0, b = 1.3999;

	//valores iniciais
	float x0 = 0, y0 = 0;

	float h = 0.1, h1 = h / 2, h2 = h1 / 2;
	float x = x0;
	float y = y0, y1 = y0, y2 = y0;

	//Calcular S com h
	while (x <= b) {
		y = y + h*f(x + h / 2, y + h / 2 * f(x, y));
		x = x + h;
	}

	cout << "y: " << y << endl;

	//Calcular S' com h' = h/2
	x = x0;
	while (x <= b) {
		y1 = y1 + h1*f(x + h1 / 2, y1 + h1 / 2 * f(x, y1));
		x = x + h1;
	}

	cout << "y1: " << y1 << endl;

	//Calcular S'' com h'' = h'/2
	x = x0;
	while (x <= b) {
		y2 = y2 + h2*f(x + h2 / 2, y2 + h2 / 2 * f(x, y2));
		x = x + h2;
	}

	cout << "y2: " << y2 << endl;

	// Qc tem que ser aproxidamente 4, se nao, dividir h/2 e fazer novamente
	cout << "QC = " << (y1 - y) / (y2 - y1) << endl;

	cout << "E = " << (y2 - y1) / 3 << endl;
}


void rk4() {
	//intervalo de integracao
	float a = 0, b = 1.3999;

	//valores iniciais
	float x0 = 0, y0 = 0;

	float h = 0.1, h1 = h / 2, h2 = h1 / 2;
	float x = x0;
	float y = y0, y1 = y0, y2 = y0;

	//Calcular S com h
	while (x <= b) {
		double dy1 = h*f(x, y);
		double dy2 = h*f(x + h / 2, y + dy1 / 2);
		double dy3 = h*f(x + h / 2, y + dy2 / 2);
		double dy4 = h*f(x + h, y + dy3);
		y = y + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		x = x + h;
	}

	cout << "y: " << y << endl;

	//Calcular S' com h' = h/2
	x = x0;
	while (x <= b) {
		double dy1 = h1*f(x, y1);
		double dy2 = h1*f(x + h1 / 2, y1 + dy1 / 2);
		double dy3 = h1*f(x + h1 / 2, y1 + dy2 / 2);
		double dy4 = h1*f(x + h1, y1 + dy3);
		y1 = y1 + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		x = x + h1;
	}

	cout << "y1: " << y1 << endl;

	//Calcular S'' com h'' = h'/2
	x = x0;
	while (x <= b) {
		double dy1 = h2*f(x, y2);
		double dy2 = h2*f(x + h2 / 2, y2 + dy1 / 2);
		double dy3 = h2*f(x + h2 / 2, y2 + dy2 / 2);
		double dy4 = h2*f(x + h2, y2 + dy3);
		y2 = y2 + dy1 / 6 + dy2 / 3 + dy3 / 3 + dy4 / 6;
		x = x + h2;
	}

	cout << "y2: " << y2 << endl;

	// Qc tem que ser aproxidamente 16, se nao, dividir h/2 e fazer novamente
	cout << "QC = " << (y1 - y) / (y2 - y1) << endl;

	cout << "E = " << (y2 - y1) / 15 << endl;
}

int main() {

	cout << "-- Euler --\n\n";
	euler();

	cout << "\n-- RK2 --\n\n";
	rk2();

	cout << "\n-- RK4 --\n\n";
	rk4();

	cin.get();
	return 0;
}
