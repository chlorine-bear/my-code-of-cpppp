#include <iostream>
using namespace std;
int main()
{
    cout << "Please enter your salary: ";
    double salary;
    double tax;
    while ((cin >> salary) && salary >= 0)
    {
        if (salary <= 5000)
        {
            tax = 0;
        }
        else if (salary <= 15000)
        {
            tax = (salary - 5000) * 0.1;
        }
        else if (salary <= 35000)
        {
            tax = 1000 + (salary - 15000) * 0.15;
        }
        else
        {
            tax = 4000 + (salary - 35000) * 0.2;
        }
    cout << "Your tax is " << tax
         << "\nPlease enter your salary: ";
    }
    return 0;
}