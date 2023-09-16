#include <iostream>
double sqr(double a, int n){
    double ans = 1;
    for (int i = 1; i <= n; i++){
        ans = ans * a;
    }
    return ans;
}
int main(){
    using namespace std;
    int ft;
    double inch, pound;
    cout << "Enter your height in ft: ";
    cin >> ft;
    cout << "Enter your height in inch: ";
    cin >> inch;
    cout << "Enter your weight in pound: ";
    cin >> pound;
    double meter = (ft * 12 + inch) * 0.0254;
    double kg = pound / 2.2;
    double bmi = kg / sqr(meter, 2);
    cout << "Your BMI is " << bmi;
    return 0;
}