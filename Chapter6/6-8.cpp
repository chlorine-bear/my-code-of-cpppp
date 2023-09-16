#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
    string doc;
    ifstream file;
    cout << "Document name: ";
    getline(cin, doc);
    file.open(doc);
    if (! file.is_open())
    {
        cout << "Could not open the file\n"
             << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    int num = 0;
    file >> ch;
    while (file.good())
    {
        ++num;
        file >> ch;
    }
    if (file.eof())
    {
        cout << "End of file reached.\n";
    }
    else if (file.fail())
    {
        cout << "Input terminated by data mismatch.\n";
    }
    else
    {
        cout << "Input terminated for unknown reason.\n";
    }
    cout << num << " chars in " << doc;
    file.close();
    return 0;
}