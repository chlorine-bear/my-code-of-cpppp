#include <iostream>
#include "golf.h"
using namespace std;

int main()
{
    cout << "Enter your amount of golf list: ";
    int amount;
    while (!(cin >> amount))
        cout << "Check your input: ";
    golf * glist = new golf [amount];

    int real_amount = 0;
    for (int i = 0; i < amount; ++i)
    {
        cout << endl;
        if (!(setgolf(glist[i])))
            break;
        ++real_amount;
    }
    
    for (int i = 0; i < real_amount; ++i)
    {
        cout << "\nRevalue the fullname: ";
        char temp[Len];
        cin.getline(temp, Len).get();
        setgolf(glist[i], temp, glist[i].handicap);
    }
    
    for (int i = 0; i < real_amount; ++i)
    {
        cout << "\nRevalue the handicap: ";
        int temphc;
        while (!(cin >> temphc))
            cout << "Check your input: ";
        handicap(glist[i], temphc);
    }
    
    for (int i = 0; i < real_amount; ++i)
    {
        cout << endl;
        showgolf(glist[i]);
    }

    delete [] glist;
    return 0;
}