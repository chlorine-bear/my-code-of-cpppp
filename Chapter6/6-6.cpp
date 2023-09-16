/*Failed Coding*/
#include <iostream>
#include <string>
using namespace std;
struct donation
{
    string name;
    double money;
};
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    donation * donalist = new donation [num];
    for (int i = 0; i < num; i++)
    {
        cout << "No." << i + 1 << " - Enter the name: ";
        getline(cin, (* (donalist + i)).name);
        cout << "No." << i + 1 << " - Enter the money: ";
        cin >> (* (donalist + i)).money;
    }
    bool * test = new bool [num];
    for (int i = 0; i < num; i++)
    {
        test[i] = (((* (donalist + i)).money) > 10000) ? true : false;
    }
    int add = 0;
    cout << "Grand Patrons:";
    for (int i = 0; i < num; i++)
    {
        if (test[i])
        {
            ++add;
            cout << "\nNo." << i + 1 << " \t"
                 << "Name: " << (* (donalist + i)).name
                 << "\n\t\tMoney: " << (* (donalist + i)).money;
        }
    }
    if (add == 0)
    {
        cout << "\nnone";
    }
    add = 0;
    cout << "\nPatrons:";
    for (int i = 0; i < num; i++)
    {
        if (! test[i])
        {
            ++add;
            cout << "\nNo." << i + 1 << " \t"
                 << "Name: " << (* (donalist + i)).name
                 << "\n\t\tMoney: " << (* (donalist + i)).money;
        }
    }
    if (add == 0)
    {
        cout << "\nnone";
    }
    delete [] donalist;
    delete [] test;
    return 0;
}