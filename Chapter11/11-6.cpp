#include <iostream>
#include "stonewt.h"
using namespace std;

int main()
{
    Stonewt stolist[6] = {(62.3), (27.5), (13.2)};
    for (int i = 3; i < 6; ++i)
    {
        stolist[i] = stolist[i - 3] - stolist[i - 2];
    }

    int max = 0, min = 0, num = 0;
    Stonewt temp(11.00);
    for (int i = 0; i < 6; ++i)
    {
        if (stolist[i] >= temp)
            ++num;
        if (stolist[i] > stolist[max])
            max = i;
        else if (stolist[i] < stolist[min])
            min = i;
    }
    
    cout << "The max: " << stolist[max] << '\n'
         << "The min: " << stolist[min] << '\n'
         << "There are " << num << " elements bigger than 11.\n";
    return 0;
}