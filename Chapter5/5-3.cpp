#include <iostream>
int main(){
    using namespace std;
    double ans = 0;
    double i = 0;
    do {
        cout << "Your number here: ";
        cin >> i;
        ans += i;
        cout << "The summary is " << ans << endl;
    } while (i != 0);
    return 0;
}