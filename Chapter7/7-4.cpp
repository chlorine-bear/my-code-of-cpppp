#include <iostream>
using namespace std;
long double probability(unsigned range, unsigned picks);
int main()
{
    unsigned range, picks;
    long double p1, p2;
    cout << "Enter the total number of choices on the game card and\n"
         << "the number of picks allowed in Field 1: ";
    while ((cin >> range >> picks) && picks <= range)
    {
        p1 = probability(range, picks);
        cout << "Next two numbers in Field 2: " ;
        if ((cin >> range >> picks) && picks <= range)
        {
            p2 = probability(range, picks);
        }
        else break;
        cout << "You have one chance in "
             << p1 * p2 << " of winning.\n"
             << "Next two numbers in Field 1: ";
    }
    cout << "Bye!";
    return 0;
}
long double probability(unsigned range, unsigned picks)
{
    long double ans = 1;
    for (unsigned i = range, j = picks; j > 0; --i, --j)
    {
        ans *= i/j;
    }
    return ans;
}