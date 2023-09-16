#include <iostream>
using namespace std;
double aver(double x, double y);
int main()
{
    while (1)
    {
        double x, y;
        cout << "The first number: ";
        cin >> x;
        cout << "The second number: ";
        cin >> y;
        if (x * y == 0)
        {
            break;
        }
        cout << aver(x, y) << endl;
    }
    return 0;    
}
double aver(double x, double y)
{
    return 2.0 * x * y / (x + y);
}