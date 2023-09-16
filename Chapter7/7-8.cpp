#include <iostream>
#include <string>
using namespace std;
string seasons = "SpringSummerFall \bWinter";
void fill(double * pa);
void show(double * pa);
int main ()
{
    double expenses[4];
    fill(expenses);
    show(expenses);
    return 0;
}
void fill(double * pa)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter ";
        for (int j = 0; j < 6; j++)
        {
            cout << seasons[6 * i + j];
        }
        cout << " expenses: ";
        cin >> * (pa + i);
    }
}
void show(double * pa)
{
    double total = 0;
    cout << "EXPENSES\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << seasons[6 * i + j];
        }
        cout << ": " << * (pa + i) << endl;
        total += * (pa + i);
    }
    cout << "Total: " << total << endl;
}