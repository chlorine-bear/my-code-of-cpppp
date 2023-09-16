#include <iostream>
using namespace std;
unsigned long long jc(int n);
int main()
{
    int num;
    cout << "Enter a number: ";
    while ((cin >> num) && num >= 0)
    {
        cout << jc(num) << endl
             << "Enter another number: ";
    }
    cout << "Bye!";
    return 0;
}
unsigned long long jc(int n)
{
    switch (n)
    {
    case 0:
    case 1:
        return 1;
        break;
    default:
        return n * jc(n - 1);
        break;
    }
}