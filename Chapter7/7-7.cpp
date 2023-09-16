#include <iostream>
using namespace std;
const int Max = 5;
double * fill_array(double * ar, int limit);
void show_array(const double * ar, const double * end);
void revalue(double r, double * ar, double * end);
int main()
{
    double properties[Max];
    double * endele = fill_array(properties, Max);
    show_array(properties, endele);
    if (endele != properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, endele);
        show_array(properties, endele);
    }
    cout << "Done!\n";
    return 0;
}
double * fill_array(double * ar, int limit)
{
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            break;
        }
        * (ar + i) = temp;
    }
    return ar + i;
}
void show_array(const double * ar, const double * end)
{
    for (int i = 0; ar + i != end; i++)
    {
        cout << "Property #" << i + 1 << ": $"
             << * (ar + i) << endl;
    }
}
void revalue(double r, double * ar, double * end)
{
    for (int i = 0; ar + i != end; i++)
    {
        * (ar + i) *= r;
    }
}