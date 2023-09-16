#include <iostream>
#include <array>
int main(){
    using namespace std;
    array<double, 3> t;
    for (int i = 0; i < 3; i++){
        cout << "Enter your time (" << i + 1 << "): ";
        cin >> t[i];
    }
    double avr = 0;
    for (int j = 0; j < 3; j++){
        avr += t[j];
    }
    avr = avr / 3.0;
    cout << "You entered 3 scores. Your average score is " << avr;
    return 0;
}