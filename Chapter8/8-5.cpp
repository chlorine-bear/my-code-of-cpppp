#include <iostream>
using namespace std;

template<typename T>
T max5(T lst[])
{
    T max = lst[0];
    for (int i = 1; i < 5; ++i)
        max = max > lst[i] ? max : lst[i];
    return max;
}

int main()
{
    int lst1[5] {5, 8, 16, 12, 13};
    double lst2[5] {6.0, 8.6, 9.1, 3.3, 4.5};

    cout << max5(lst1) << endl;
    cout << max5(lst2) << endl;
    return 0;
}