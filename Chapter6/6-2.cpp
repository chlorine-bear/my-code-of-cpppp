#include <iostream>
using namespace std;
int main()
{
    double donation[10];
    int point = 0;
    double sum = 0;
    while (point < 10 && (cin >> donation[point]))
    {
        sum += donation[point];
        ++point;
    }
    double average = sum / point;
    cout << "The average number is " << average << endl;
    int nums = 0;
    for (int i = 0; i < point; i++)
    {
        if (donation[i] > average)
        {
            ++nums;
        }
    }
    cout << nums << " numbers are bigger than average.\n";
    return 0;
}