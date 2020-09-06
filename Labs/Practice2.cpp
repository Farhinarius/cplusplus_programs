#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
#define pi 3.14

///////////////////////////////////
/// �������

double f(double x)
{
	return sin(x)*x*x;
}

///////////////////////////////////
/// ����� ����
double findRoot(double a, double b, double e)
{
	while (fabs(f(b)) > e)
	{
		a = b - ((b - a) * f(b)) / (f(b) - f(a));
		b = a - ((a - b) * f(a)) / (f(a) - f(b));
	}
	return b;
}

///////////////////////////////////
/// ����� ��
double fi(double x, double L) {

	return  x + L * f(x);
}

///////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int k = 0;
	double c;
	int L = 0.5;
	double y, x, a, b, e;
	
	////////////////////////////////////////////////////////
	
	cout << "/---------------------------------------------/";
	cout << "\n ������ �������: sin(x)*x^2"; cout << endl;
	cout << "/---------------------------------------------/"; cout << endl;
	

	cout << "\n ������� ��������� ������� a � b: " << endl;
	cin >> a; cin >> b;
	cout << "\n ������� Epsilon(��������): "; cin >> e; 
	cout << "/---------------------------------------------/";
	
	cout << "\n �������� �����, ������� ������ ������� ����� ���������: ";
	cout << "\n 1.���������� ������ ������� ����";
	cout << "\n 2.���������� ������ ������� ����������� ������� �������";
	cout << "\n 3.���������� ������ ������� �������� ��������"; 
	cout << "\n 0.����� �� ����"; cout << endl;
	cin >> n;
	
	//////////////////////////////////////////////////////////////

	while (n != 0)
	{ 
		switch (n)
		{
		case 1:
			cout << "/---------------------------------------------/";
			cout << "\n ������ ��������� x=" << findRoot(a, b, e) << endl; 
			cout << "�������� ���������� �������� �� ������� ����: "; cin >> n;
			cout << "/---------------------------------------------/"; cout << endl;

		case 2:
			cout << "/---------------------------------------------/";
			do {
				c = (a + b) / 2;
				if (f(c)*f(a) <= 0) b = c;
				else a = c;

				k++;

			} while (fabs(a - b) >= e);
			cout << "\nc=" << c << "\n";
			cout << "\nk=" << k << "\n";
			k = 0;
			cout << "\n�������� ���������� �������� �� ������� ����: "; cin >> n;
			cout << "/---------------------------------------------/"; cout << endl;

		case 3:
			cout << "/---------------------------------------------/" << endl;
			cout << "x="; cin >> x;
			do {
				y = fi(x, L);
				b = fabs(x - y);
				x = y;
				k += 1;
			} while (b >= e);
			cout << "\nc=" << x << "\n";
			cout << "\nk=" << k << "\n";
			k = 0;
			cout << "\n�������� ���������� �������� �� ������� ����: "; cin >> n;
			cout << "/---------------------------------------------/"; cout << endl;

		case 0:
			exit(0);

		default: cout << "������ �����, ���������� ����� "; cin >> n;
		}
	}
	return 0;
}