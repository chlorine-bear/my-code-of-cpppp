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
    unsigned long steps, maxsteps, minsteps, sum;
    int times;
    double target, dstep;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout << "Enter test times: ";
        if (!(cin >> times))
            break;
        maxsteps = minsteps = sum = 0;
        
        for (int i = 0; i < times; ++i)
        {
            steps = 0;
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                ++steps;
            }

            maxsteps = steps > maxsteps ? steps : maxsteps;
            minsteps = (i == 0 || steps < minsteps) ?
                       steps : minsteps;
            sum += steps;
            result.reset(0, 0);
        }
        
        cout << "Maxsteps: " << maxsteps << '\n'
             << "Minsteps: " << minsteps << '\n'
             << "Average:  " << (double)sum / times << '\n'
             << "Enter step length: ";
    }
    
    cout << "Bye!\n" ;
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;    
}