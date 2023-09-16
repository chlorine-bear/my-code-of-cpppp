#include <iostream>
#include <string>
using namespace std;

int t = 0;
void print(string * str, int j = 0)
{
    ++t;
    if(j)
        for (int i = 0; i < t; ++i)
            cout << * str << endl;
    else
        cout << * str << endl;
}

int main()
{
    string str = "1145141919810";
    print(&str);
    print(&str, 1);
    print(&str);
    print(&str, 0);
    print(&str);
    print(&str, 8);
    return 0;
}