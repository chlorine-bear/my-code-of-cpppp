#include <iostream>
#include "vect.h"
#include <ctime>
#include <cstdlib>
using namespace std;
using VECTOR::Vector;
//using VECTOR::operator<<;
//using VECTOR::operator*;

int main()
{
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0, 0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
            cout << "No." << steps << '\n'
                 << result << '\n'
                 << "Length = " << result.magval() << '\n';
        }
        
        cout << "After " << steps
             << " steps, the subject has the following location:\n"
             << result << '\n';
        result.polar_mode();
        cout << "or\n" << result << '\n'
             << "Average outward distance per step = "
             << result.magval() / steps << '\n';
        
        steps = 0;
        result.reset(0, 0);
        cout << "Enter step length: ";
    }
    
    cout << "Bye!\n" ;
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;    
}