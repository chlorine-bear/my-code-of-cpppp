/*Not running successfully*/
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char inp[1000];
    cout << "Enter words (to stop, type the word done):\n";
    for (int i = 0; i < 3; ++i)
        cin.get(inp[i]);
    int test = 1;
    int point = 3;
    int num = 0;
    char spl[5] = {'\n','\n','\n','\n','\n'};
    char DONE[5] = {'d','o','n','e','\n'};
    while ((point < 1000) && test)
    {
        cin.get(inp[point]);
        ++point;
        if ((inp[point] == '\n') || (inp[point] == ' '))
            ++num;
        for (int i = 0; i < 4; ++i)
            spl[i] = inp[point - 3 + i];
        test = strcmp(spl, DONE);
    }
    cout << "You entered a total of " << num << " words.\n";
    return 0;
}