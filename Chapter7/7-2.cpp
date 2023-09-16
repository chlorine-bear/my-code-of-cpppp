#include <iostream>
using namespace std;
int inp(double score[]);
void outp(double score[], int num);
double aver(double score[], int num);
int main()
{
    double score[10];
    int num = inp(score);
    outp(score, num);
    cout << aver(score, num);
    return 0;
}
int inp(double score[])
{
    double data;
    int i;
    for (i = 0; i < 10; i++)
    {
        cout << "Enter the No." << i + 1 << " score: ";
        cin >> data;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            break;
        }
        score[i] = data;
    }
    return i;
}
void outp(double score[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << score[i] << " ";
    }
    cout << endl;
}
double aver(double score[], int num)
{
    double total = 0;
    for (int i = 0; i < num; i++)
    {
        total += score[i];
    }
    return total / num;
}