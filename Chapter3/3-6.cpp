#include <iostream>
int main(){
    using namespace std;
    double mile, gl;
    cout << "You have run __________ miles\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> mile;
    cout << "You have used __________ gl oil\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> gl;
    cout << "You can run " << mile / gl << " miles with 1 gl oil.\n";
    double km, L;
    cout << "You have run __________ km\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> km;
    cout << "You have used __________ L oil\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> L;
    cout << "You may use " << L / km * 100 << " L oil to run 100 km.";
    return 0;
}