#include <iostream>
using namespace std;
double trans(double);
int main(){
    double cels, fahr;
    cout << "Please enter a Celsius value: ";
    cin >> cels;
    fahr = trans(cels);
    cout << cels << " degrees Celsius is " << fahr << " degrees Fahrenheit.";
    return 0;
}
double trans(double cels){
    return cels * 1.8 + 32.0;
}