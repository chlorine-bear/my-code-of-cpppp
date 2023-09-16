#include <iostream>
using namespace std;

template<typename T>
T maxn(T lst[], int len)
{
    T max = * lst;
    for(int i = 1; i < len; ++i)
        max = max > lst[i] ? max : lst[i];
    return max;
}

template<> char * maxn(char * lst[], int len)
{
    char * maxptr = * lst;
    int num, last = 0;
    for (int i = 0; i < len; ++i)
    {
        num = 0;
        while (lst[i][num] != '\0')
            ++num;
        if(num > last)
        {
            maxptr = lst[i];
            last = num;
        }
    }
    return maxptr;
}

int main()
{
    int lst1[6] {1, 6, 3, 5, 2, 4};
    double lst2[4] {1.06, 2.41, 2.42, 2.07};
    char str1[] = "ierjijofafejuehaefiu\0";
    char str2[] = "ierjijofafejuehajfeiaefiu\0";
    char str3[] = "ieajioefjeiou\0";
    char str4[] = "ierjijofafejuesfejehaefiu\0";
    char str5[] = "ierjijofafejuehdaffaefiu\0";
    char * lst3[5] = {str1, str2, str3, str4, str5};

    cout << maxn(lst1, 6) << endl
         << maxn(lst2, 4) << endl
         << endl;
    
    for (int i = 0; i < 5; ++i)
        cout << (void *)(lst3[i]) << endl;
    
    cout << endl
         << (void *) maxn(lst3, 5)
         << endl;

    return 0;
}