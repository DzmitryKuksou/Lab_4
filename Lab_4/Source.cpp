#include<iostream>
using namespace std;
typedef double(*Formula)(int, double, double);
bool IsDataValid(double, double, double, int);
double DualConversion(double, double, double, int, Formula);
double FormulaOfAverageRectangle(int, double, double);
double FormulaOfRightRectangle(int, double, double);
int main()
{
	double a, b, eps;
	int n;
	while (true)
	{
		cout << "Begin Of Segment:";
		cin >> a;
		cout << "End Of Segment:";
		cin >> b;
		cout << "Epsilon:";
		cin >> eps;
		cout << "the number of n:";
		cin >> n;
		if (IsDataValid(a, b, eps, n))break;
		system("cls");
	}
	Formula formula = FormulaOfRightRectangle;
	cout << "result for Right Rectangle:\n";
	cout << DualConversion(eps, a, b, n, formula) << endl;
	cout << "result for Average Rectangle:\n";
	formula = FormulaOfAverageRectangle;
	cout << DualConversion(eps, a, b, n, formula);
	system("pause");
	return 0;
}
double FormulaOfRightRectangle(int n, double a, double b)
{
	double Integral = 0, x = 0;
	double h = (b - a) / n;
	for (int i = 0; i <= n; i++)
	{
		x = a + i*h;
		Integral = h*(sin(x) / x);
	}
	return Integral;
}
double DualConversion(double eps, double a, double b, int n, Formula formula)
{
	double IntegralForN = 0, IntegralFor2N = 0;
	while (fabs(IntegralForN - IntegralFor2N) > eps)
	{
		IntegralForN = formula(n, a, b);
		IntegralFor2N = formula(2*n, a, b);
		n *= 2;
	}
	double Integral = formula(n, a, b);
	return Integral;
}
bool IsDataValid(double a, double b, double eps, int n)
{
	if (a < b && n > 0 && eps < 1 && eps > 0)return 1;
	else cout << "Enter: a<b, 0<eps<1, n>0\n"; system("pause");
	return 0;
}
double FormulaOfAverageRectangle(int n, double a, double b)
{
	double Integral = 0, x = 0;
	double h = (b - a) / n;
	for (int i = 0; i < n; i++)
	{
		x = a + i*h;
		Integral = h*(sin(x + h / 2) / (x + h / 2));
	}
	return Integral;
}
