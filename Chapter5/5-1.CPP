#include <iostream>
int main(){
    using namespace std;
    int ans, min, max = 0;
    cout << "Min: ";
    cin >> min;
    cout << "Max: ";
    cin >> max;
    for (int i = min; i <= max; ++i){
        ans += i;
    }
    cout << ans;
    return 0;
}