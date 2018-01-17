#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


double f(float x) {
	return sin(x) / pow(x, 2);
}

void trapezios() {

	//intervalo de integracao
	float a = M_PI / 2;
	float b = M_PI;



	//Calcular S com h
	float h = M_PI / 8;
	int n = (b - a) / h;

	int i = 1;
	double res = f(a) + f(b);

	while (i < n) {
		res += 2 * f(a + i*h);
		i++;
	}
	res *= h / 2;

	cout << "S = " << res << endl;

	//Calcular S' com h' = h/2
	h /= 2;
	n = (b - a) / h;

	i = 1;
	double res1 = f(a) + f(b);

	while (i < n) {
		res1 += 2 * f(a + i*h);
		i++;
	}

	res1 *= h / 2;

	cout << "S' = " << res1 << endl;

	//Calcular S'' com h'' = h'/2
	h /= 2;
	n = (b - a) / h;

	i = 1;
	double res2 = f(a) + f(b);

	while (i < n) {
		res2 += 2 * f(a + i*h);
		i++;
	}

	res2 *= h / 2;

	cout << "S'' = " << res2 << endl;

	// Qc tem que ser aproxidamente 4, se nao, dividir h/2 e fazer novamente
	cout << "Qc = " << (res1 - res) / (res2 - res1) << endl;
	cout << "E = " << (res2 - res1) / 3 << endl;

}

void simpson() {
	//intervalo de integracao
	float a = M_PI / 2;
	float b = M_PI;



	//Calcular S com h
	float h = M_PI / 8;
	int n = (b - a) / h;

	int i = 1;
	double res = f(a) + f(b);

	while (i < n) {
		if (i % 2 == 0)
			res += 2 * f(a + i*h);
		else
			res += 4 * f(a + i*h);
		i++;
	}
	res *= h / 3;

	cout << "S = " << res << endl;

	//Calcular S' com h' = h/2
	h /= 2;
	n = (b - a) / h;

	i = 1;
	double res1 = f(a) + f(b);

	while (i < n) {
		if(i%2 == 0) 
			res1 += 2 * f(a + i*h);
		else
			res1 += 4 * f(a + i*h);
		i++;
	}

	res1 *= h / 3;

	cout << "S' = " << res1 << endl;

	//Calcular S'' com h'' = h'/2
	h /= 2;
	n = (b - a) / h;

	i = 1;
	double res2 = f(a) + f(b);

	while (i < n) {
		if (i % 2 == 0)
			res2 += 2 * f(a + i*h);
		else
			res2 += 4 * f(a + i*h);
		i++;
	}

	res2 *= h / 3;

	cout << "S'' = " << res2 << endl;

	// Qc tem que ser aproxidamente 16, se nao dividir h/2 e fazer novamente
	cout << "Qc = " << (res1 - res) / (res2 - res1) << endl;

	//Neste caso dá 14.35, logo é preciso calcular S'''
	h /= 2;
	n = (b - a) / h;

	i = 1;
	double res3 = f(a) + f(b);
	
	while (i < n) {
		if (i % 2 == 0)
			res3 += 2 * f(a + i*h);
		else
			res3 += 4 * f(a + i*h);
		i++;
	}

	res3 *= h / 3;

	cout << "\nS''' = " << res3 << endl;

	cout << "Qc = " << (res2 - res1) / (res3 - res2) << endl;

	cout << "E = " << (res3 - res2) / 15 << endl;

}

int main() {

	cout << "-- Metodo dos trapezios --\n\n";
	trapezios();

	cout << "\n-- Metodo de Simpson -- \n\n";
	simpson();

	cout << endl;
	cin.get();
	return 0;
}