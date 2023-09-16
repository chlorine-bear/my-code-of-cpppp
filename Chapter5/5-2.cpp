#include <iostream>
#include <array>
using namespace std;
int main(){
    array<long double, 101> ans;
    ans[0] = ans[1] = 1;
    for(int i = 2; i <= 100; ++i)
        ans[i] = i * ans[i - 1];
    cout << ans[100];
    return 0;
}