#include <iostream>
using namespace std;
double add(double, double);
double times(double, double);
double calculate(double, double, double (*)(double, double));
double add(double a, double b)
{
    return a + b;
}
double times(double a, double b)
{
    return a * b;
}
double calculate(double a, double b, double (* pf)(double, double))
{
    return (* pf)(a, b);
}
int main()
{
    double x, y;
    cout << "Please enter 2 numbers: ";
    while (cin >> x >> y)
    {
        cout << calculate(x, y, add) << endl;
        cout << "Please enter 2 numbers: ";
        if (!(cin >> x >> y))
        {
            break;
        }
        cout << calculate(x, y, times) << endl;
        cout << "Please enter 2 numbers: ";
    }
    cout << "Bye!\n";
    return 0;
}