#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void toUp(string & str)
{
    for (int i = 0; i < str.size(); ++i)
        str[i] = toupper(str[i]);    
}

int main()
{
    string temp;
    cout << "Enter a string (q to quit): ";
    getline(cin, temp);
    while (temp != "q")
    {
        toUp(temp);
        cout << temp << endl
             << "Next string (q to quit): ";
        getline(cin, temp);
    }
    cout << "Bye." << endl;
    return 0;
}