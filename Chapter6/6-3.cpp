#include <iostream>
using namespace std;
int main()
{
    cout << "Please enter one of the following choices:\n"
         << "c) carnivore   p) pianist\n"
         << "t) tree        g) game\n";
    char choice;
    bool test;
    do
    {
        test = false;
        cout << "Please enter a c, p, t, or g: ";
        cin >> choice;
        switch (choice + 1)
        {
        case ('c' + 1):
            cout << "A maple is a carnivore.\n";
            break;
        case ('p' + 1):
            cout << "A maple is a pianist.\n";
            break;
        case ('t' + 1):
            cout << "A maple is a tree.\n";
            break;
        case ('g' + 1):
            cout << "A maple is a game.\n";
            break;
        default:
            cin.get();
            test = true;
            break;
        }
    } while (test);
    return 0;
}