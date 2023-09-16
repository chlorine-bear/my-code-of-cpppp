#include <iostream>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main()
{
    std::srand(std::time(0));

    cout << "Case Study: Bank of Heather ATM\n";
    cout << "Enter maximum size of queue: ";
    return 0;
}