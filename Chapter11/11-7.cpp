#include <iostream>
#include "complex0.h"
using namespace std;

int main()
{
    complex a(3, 4);
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "square of distance is " << c.dist() << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "a / c is " << a / c << '\n';
        cout << "c / 6 is " << c / 6 << '\n';
        cout << "c * 2 is " << c * 2 << '\n';
        cout << "4 * c is " << 4 * c << '\n';
        cout << "unit of c is " << c.unit() << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}