#include <iostream>
#include "time.h"
using namespace std;

int main()
{
    Time aida(3, 35), tosca(2, 48), temp;

    cout << "Aida and Tosca:\n"
         << aida << "; " << tosca << '\n';
    temp = aida + tosca;
    cout << "Aida + Tosca = " << temp << '\n';
    temp = aida * 1.17;
    cout << "Aida * 1.17 = " << temp << '\n'
         << "10.0 * Tosca = " << 10.0 * tosca << '\n';

    return 0;
}