# Homework
 /*
	Хафизов Азат 1 семинар 22 задача
 Дополнить калькулятор возможностью вводить операнды в восьмеричной системе
 счисления.
 Для любого операнда префикс «o» означает, что этот операнд задан в восьмеричной системе счисления (не
 более 2-х разрядов): o10+6=14. Числа без префикса считаются десятичными. Результат печатать в
 десятичной системе счисления.
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(int argc, char* argv[])
{
	double r1 = 0, r2 = 0, r3;
	char m[4], n[4];
	char op;
	if (argc - 1 != 3) {
		if (argc - 1 == 2) {
			if (argv[1][0] == '+' || argv[1][0] == '-' || argv[1][0] == '*' || argv[1][0] == '/') {
				cout << "Please, enter r1" << endl << flush;
				cin >> m;
				op = argv[1][0];
				for (int i = 0; i<3; i++)
					n[i] = argv[2][i];
			}
			else if (argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*' || argv[2][0] == '/') {
				cout << "Please, enter r2" << endl << flush;
				cin >> n;
				op = argv[2][0];
				for (int i = 0; i<3; i++)
					m[i] = argv[1][i];
			}
			else {
				cout << "Please, enter op" << endl << flush;
				cin >> op;
				for (int i = 0; i<3; i++) {
					m[i] = argv[1][i];
					m[i] = argv[1][i];
				}
			}
		}
		if (argc - 1 == 1) {
			if (argv[1][0] == '+' || argv[1][0] == '-' || argv[1][0] == '*' || argv[1][0] == '/') {
				cout << "Please, enter r1 and r2" << endl << flush;
				cin >> m >> n;
				op = argv[1][0];
			}
			else {
				cout << "Please, enter op and r2" << endl << flush;
				cin >> op >> n;
				for (int i = 0; i<3; i++) {
					m[i] = argv[1][i];
				}
			}
		}
		if (argc - 1 == 0) {
			cout << "Please, enter r1, op and r2" << endl << flush;
			cin >> m >> op >> n;
		}
		if (argc - 1>3 || argc - 1<0) {
			cout << "Oops!" << flush;
			return 1;
		}
	} 
	else {
		op = argv[2][0];
		for (int i = 0; i<3; i++)
		{
			m[i] = argv[1][i];
			n[i] = argv[3][i];
		}
	}
	int k = 0, p = 0;
	if (m[0] == 'o')
	{
		for (int i = 1; m[i] != '\0'; i++)
			p++;
		p--;
		for (int i = 1; m[i] != '\0'; i++)
		{
			switch (m[i])
			{
			case '1':k = 1; break;
			case '2':k = 2; break;
			case '3':k = 3; break;
			case '4':k = 4; break;
			case '5':k = 5; break;
			case '6':k = 6; break;
			case '7':k = 7; break; 
			case '0':k = 0; break;
			}
			r1 = r1 + k*pow(8.0, p);
			p--;
		}
		cout << r1 << endl;
	}
	else {
		r1 = atof(m);
		cout << r1 << endl;
	}
	p = 0;
	if (n[0] == 'o')
	{
		for (int i = 1; n[i] != '\0'; i++) {
			p++;
		}
		p--;
		for (int i = 1; n[i] != '\0'; i++) {
			switch (n[i])
			{
			case '1':k = 1; break;
			case '2':k = 2; break;
			case '3':k = 3; break;
			case '4':k = 4; break;
			case '5':k = 5; break;
			case '6':k = 6; break;
			case '7':k = 7; break;
			case '0':k = 0; break;
			}
			r2 = r2 + k*pow(8.0, p);
			p--;
		}
		cout << r2 << endl;
	}
	else {
		r2 = atof(n);
		cout << r2 << endl;
	}
	switch (op) {
	case '+': r3 = r1 + r2; break;
	case '-': r3 = r1 - r2; break;
	case '*': r3 = r1 * r2; break;
	case '/':
		if (fabs(r2)<1.0E-10) {
			cout << "Divide by zero!" << flush;
			return 1;
		}
		r3 = r1 / r2;
		break;
	default:
		cout << "Error!" << flush;
		return 1;
	}
	cout << r1 << ' ' << op << ' ' << r2 << ' ' << '=' << ' ' << r3 << endl << flush;
	system("pause");
	return 0;
}
