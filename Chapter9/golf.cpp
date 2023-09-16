// golf.cpp -- for 9-1.cpp

#include <iostream>
#include "golf.h"
using namespace std;

void setgolf(golf & g, const char * name, int hc)
{
    for (int i = 0; i < Len; ++i)
        g.fullname[i] = name[i];
    g.handicap = hc;
}

int setgolf(golf & g)
{
    cout << "Please enter the fullname :";
    cin.getline(g.fullname, Len).get();
    cout << "Please enter the handicap: ";
    while (!(cin >> g.handicap))
        cout << "Check your input: ";
    return g.fullname[0] ? 1 : 0;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    cout << "Fullname: " << g.fullname << endl
         << "Handicap: " << g.handicap << endl;
}