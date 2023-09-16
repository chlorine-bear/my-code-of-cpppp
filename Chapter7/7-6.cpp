#include <iostream>
using namespace std;
int Fill_array(double * arr, int num);
void Show_array(double * arr, int num);
void Reverse_array(double * arr, int num);
int main()
{
    cout << "Enter the max length: ";
    int max;
    cin >> max;
    double * arr = new double [max];
    int num = Fill_array(arr, max);
    Show_array(arr, num);
    Reverse_array(arr, num);
    Show_array(arr, num);
    Reverse_array(arr + 1, num - 2);
    Show_array(arr, num);
    delete [] arr;
    return 0;
}
int Fill_array(double * arr, int num)
{
    cout << "Enter the number: ";
    int length = 0;
    double text;
    while (length < num && (cin >> text))
    {
        * (arr + length) = text;
        ++length;
        cout << "Enter the next number: ";
    }
    return length;
}
void Show_array(double * arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << "No." << i + 1 << ": "
             << * (arr + i) << endl;
    }
}
void Reverse_array(double * arr, int num)
{
    double save;
    for (int i = 0; i < num / 2; i++)
    {
        save = * (arr + i);
        * (arr + i) = * (arr + num - 1 - i);
        * (arr + num - 1 - i) = save;
    }
}