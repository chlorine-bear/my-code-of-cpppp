#include <iostream>
double trans(double ly){
    return ly * 63240;
}
int main(){
    double au, ly;
    using namespace std;
    cout << "Enter the number of light years: ";
    cin >> ly;
    au = trans(ly);
    cout << ly << " light years = " << au << " astronomical units.";
    return 0;
}