#include <iostream>
int main(){
    int age, month;
    using namespace std;
    cout << "Enter your age: ";
    cin >> age;
    month = age * 12;
    cout << "Your age in months is " << month;
    return 0;
}