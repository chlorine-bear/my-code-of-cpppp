#include <iostream>
using namespace std;
struct bop
{
    char fullname[50];
    char title[50];
    char bopname[50];
    int preference;
};
int main()
{
    bop boplist[5]
    {
        {"Wimp Macho", "Senior Programmer", "FALSE", 0},
        {"Raki Rhodes", "Junior Programmer", "RANDOM", 1},
        {"Celia Laiter", "Web administer", "MIPS", 2},
        {"Hoppy Hipman", "Analyst Trainee", "NULL", 1},
        {"Pat Hand", "Businessman", "LOOPY", 2}
    };
    cout << "Benevolent Order of Programmers Report\n"
         << "a. display by name     b. display by title\n"
         << "c. display by bopname  d. display by preference\n"
         << "q. quit\n" << "Enter your choice: ";
    char choice;
    while (1)
    {
        cin >> choice;
        switch (choice + 1)
        {
        case 'a' + 1:
            for (int i = 0; i < 5; i++)
            {
                cout << (boplist[i]).fullname << endl;
            }
            break;
        case 'b' + 1:
            for (int i = 0; i < 5; i++)
            {
                cout << (boplist[i]).title << endl;
            }
            break;
        case 'c' + 1:
            for (int i = 0; i < 5; i++)
            {
                cout << (boplist[i]).bopname << endl;
            }
            break;
        case 'd' + 1:
            for (int i = 0; i < 5; i++)
            {
                switch ((boplist[i]).preference)
                {
                case 0:
                    cout << (boplist[i]).fullname << endl;
                    break;
                case 1:
                    cout << (boplist[i]).title << endl;
                    break;
                case 2:
                    cout << (boplist[i]).bopname << endl;
                    break;
                }
            }
            break;
        case 'q' + 1:
            goto endline;
        default:
            cout << "Illegally input!\n";
            break;
        }
        cout << "Next choice: ";
    }
    endline: cout << "Bye!";
    return 0;
}