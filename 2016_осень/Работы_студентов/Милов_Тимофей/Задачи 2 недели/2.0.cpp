<<<<<<< HEAD
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


double count(double a, double  b, double c, double x) {
	if (c < 0 && a != 0)
		return (-a)*pow(x, 2);
	else
		if (c > 0 && a == 0)
			return (a - x) / c*x;
		else
			return x / c;
		
}


 int main() {
	double a, b, c, x, xn, dx;

	cout << "enter a" << endl;
	cin >> a;

	cout << "enter b" << endl;
	cin >> b;

	cout << "enter c" << endl;
	cin >> c;

	cout << "enter x1" << endl;
	cin >> x;

	cout << "enter xn" << endl;
	cin >> xn;

	cout << "enter step dx" << endl;
	cin >> dx;

	if (a != 0)
		cout << " a != 0 " << endl;
	else
		if (c > 0 && a == 0)
			cout << " a = 0 " << endl;
		

	while (x <= xn) {

		if (c < 0)
			cout << " c < 0 , x = " <<  x << "   " << count(a, b, c, x) << endl;
		else
			if (c > 0)
				cout << " c > 0 , x = " << x << "   " << count(a, b, c, x) << endl;
			else
				if (x = 0)
					cout << " c = 0 , x = " << x << "   " << count(a, b, c, x) << endl;
		x+= dx;
	}
	getchar();
	getchar();
	return 0;
=======
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


double count(double a, double  b, double c, double x) {
	if (c < 0 && a != 0)
		return (-a)*pow(x, 2);
	else
		if (c > 0 && a == 0)
			return (a - x) / c*x;
		else
			return x / c;
		
}


 int main() {
	double a, b, c, x, xn, dx;

	cout << "enter a" << endl;
	cin >> a;

	cout << "enter b" << endl;
	cin >> b;

	cout << "enter c" << endl;
	cin >> c;

	cout << "enter x1" << endl;
	cin >> x;

	cout << "enter xn" << endl;
	cin >> xn;

	cout << "enter step dx" << endl;
	cin >> dx;

	if (a != 0)
		cout << " a != 0 " << endl;
	else
		if (c > 0 && a == 0)
			cout << " a = 0 " << endl;
		

	while (x <= xn) {

		if (c < 0)
			cout << " c < 0 , x = " <<  x << "   " << count(a, b, c, x) << endl;
		else
			if (c > 0)
				cout << " c > 0 , x = " << x << "   " << count(a, b, c, x) << endl;
			else
				if (x = 0)
					cout << " c = 0 , x = " << x << "   " << count(a, b, c, x) << endl;
		x+= dx;
	}
	getchar();
	getchar();
	return 0;
>>>>>>> 8da3f3581c710dda478e2bf0407176a3be2dec2a
}