#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;


double f(float x, float y) {
	return exp(y - x);
}

void simpson() {
	
	//intervalos de integracao
	float a1 = 0, b1 = 0.5;
	float a2 = 0, b2 = 0.5;

	float hx = 0.25;
	int nx = (b1 - a1) / hx;  // = 2

	float hy = 0.25;
	int ny = (b2 - a2) / hy;  // = 2

	/*

      0.5 _______________________
	     |	         |           |
		 |           |           |
		 |           |	         |
	     |           |           |
	0.25 |-----------+-----------|
	     |           |           |
		 |			 |           |
		 |           |           |
	     |___________|___________|
		0			0.25		  0.5
	
	*/

	//Soma dos vertices
	double E0 = f(0, 0) + f(0.5, 0.5) + f(0, 0.5) + f(0.5, 0);
	//Soma dos pontos intermedios
	double E1 = f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5);
	//Central
	double E2 = f(0.25, 0.25);


	double res = (hx*hy / 9) * (E0 + 4 * E1 + 16 * E2);

	cout << "Res = " << res << endl;
	
}

void trapezios() {

	//intervalos de integracao
	float a1 = 0, b1 = 0.5;
	float a2 = 0, b2 = 0.5;

	float hx = 0.25;
	int nx = (b1 - a1) / hx;  // = 2

	float hy = 0.25;
	int ny = (b2 - a2) / hy; // = 2

	/*

	0.5 _______________________
	   |	       |           |
       |           |           |
       |           |	       |
	   |           |           |
   0.25|-----------+-----------|
	   |           |           |
	   |       	   |           |
	   |           |           |
	   |___________|___________|
	0			0.25		  0.5

	*/

	//Soma dos vertices
	double E0 = f(0, 0) + f(0.5, 0.5) + f(0, 0.5) + f(0.5, 0);
	//Soma dos pontos intermedios
	double E1 = f(0, 0.25) + f(0.25, 0) + f(0.5, 0.25) + f(0.25, 0.5);
	//Central
	double E2 = f(0.25, 0.25);


	double res = (hx*hy / 4) * (E0 + 2 * E1 + 4 * E2);

	cout << "Res = " << res << endl;

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