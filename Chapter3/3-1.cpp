#include <iostream>
int main(){
    using namespace std;
    cout << "Enter your height in cm here: _____\b\b\b\b\b";
    int hcm;
    cin >> hcm;
    const double trans = 100;
    double hm = hcm / trans;
    cout << "Your height in m is " << hm;
    return 0;
}