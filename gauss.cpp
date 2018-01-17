#include <iostream>
#include <math.h>
using namespace std;

void rowop(double m[3][4], int i, int j, double t) {
	for (unsigned int a = 0; a < 4; a++) {
		m[i][a] -= t*m[j][a];
	}
}


int main()
{
	double m[3][4] = {
		{ 1,5,6,2 },
		{ 7,4,2,3 },
		{ -3,6,7,5 }
	};

	for (unsigned int i = 0; i < 3; i++) {
		rowop(m, i, i, 1 - 1 / m[i][i]);        //diagonal principal a 1
		for (unsigned int j = 0; j < 3; j++) {
			if (i != j) {
				rowop(m, j, i, m[j][i]);
			}
		}
	}

	cout << "\n";
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 4; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n\n";
	}

	cin.get();
	return 0;
}