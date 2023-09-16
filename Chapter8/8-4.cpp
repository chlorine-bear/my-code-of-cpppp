#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & str, char tst[])
{
    int len = 0;
    while (tst[len] != '\0')
        ++len;
    char * ch = new char [len];
    for (int i = 0; i < len; ++i)
        ch[i] = tst[i];
    str.str = ch;
    str.ct = len;
}

void show(const stringy & str, const int t = 1)
{
    for (int i = 0; i < t; ++i)
    {
        for (int j = 0; j < str.ct; ++j)
            cout << (str.str)[j];
        cout << endl;
    }
}

void show(const char tst[], const int t = 1)
{
    int j;
    for (int i = 0; i < t; ++i)
    {
        j = 0;
        while (tst[j] != '\0')
            cout << tst[j++];
        cout << endl;
    }
}

int main()
{
    stringy beany;
    char testing[] = "Really isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);

    show("Done!");
    return 0;
}