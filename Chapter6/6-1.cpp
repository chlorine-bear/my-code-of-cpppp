#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char inp[1000];
    int point = -1;
    do
    {
        ++point;
        cin >> inp[point];
    } while (inp[point] != '@' && point < 1000);
    for (int i = 0; i < point; i++)
    {
        char ch = inp[i];
        if (islower(ch))
        {
            ch = toupper(ch);
            cout << ch;
        } else if (isupper(ch))
        {
            ch = tolower(ch);
            cout << ch;
        }
    }
    cout << endl;
    return 0;
}