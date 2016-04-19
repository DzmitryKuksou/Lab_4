#include<iostream>
using namespace std;
typedef double(*Formula)(int, double, double, double);
bool IsDataValid(double, double, double, int);
double FormulaOfAverageRectangle(int, double, double, double);
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
		system("pause");
	}
	Formula formula = FormulaOfAverageRectangle;
	cout << "Integral for n and Integral for 2*n:\n";
	formula(n, a, b, eps);
	system("pause");
	return 0;
}
bool IsDataValid(double a, double b, double eps, int n)
{
	if (a < b && n > 0 && eps < 1 && eps > 0)return 1;
	else cout << "Enter: a<b, 0<eps<1, n>0\n"; system("pause");
	return 0;
}
double FormulaOfAverageRectangle(int n, double a, double b, double eps)
{
	double IntegralForN = 0, IntegralFor2N = 0, x = 0;
	double h = (b - a) / n;
	while (true)
	{
		h = (b - a) / n;
		IntegralForN = 0, IntegralFor2N = 0;
		for (int i = 0; i < n; i++)
		{
			x = a + i*h;
			IntegralForN += h*(sin(x + h / 2) / (x + h / 2));
		}
		x = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			h = (b - a) / n;
			x = a + i*h / 2;
			IntegralFor2N += h / 2 * (sin(x + h / 4) / (x + h / 4));
		}
		if (fabs(IntegralForN - IntegralFor2N) < eps)break;
		else  n *= 2;
	}
	cout << IntegralForN << endl << IntegralFor2N;
	return IntegralForN; IntegralFor2N;
}