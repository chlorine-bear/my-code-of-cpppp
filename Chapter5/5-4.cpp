#include <iostream>
int main(){
    double daphne = 100, cleo = 100;
    int yr = 0;
    while (daphne >= cleo){
        ++yr;
        daphne += 100 * 0.1;
        cleo *= 1.05;
    }
    using namespace std;
    cout << "Daphne: " << daphne << endl;
    cout << "Cleo:" << cleo << endl;
    cout << "After " << yr << " years.";
    return 0;
}