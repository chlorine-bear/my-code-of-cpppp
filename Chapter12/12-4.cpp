#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> st1(5);
    int i = 5;

    while (st1.push(++i))
        cout << i << '\n';
    
    Stack<int> st2(st1);
    st2.pop(i);
    cout << i << '\n';

    Stack<int> st3 = st2;

    while (st3.pop(i))
        cout << i << '\n';
    
    return 0;
}