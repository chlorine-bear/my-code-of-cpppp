#include <iostream>
#include <string>
using namespace std;
struct car{
    string make;
    int year;
};
int main(){
    cout << "How many cars do you wish to catalog? ";
    int amount;
    cin >> amount;
    car * cars = new car [amount];
    for (int i = 0; i < amount; ++i){
        cout << "Car #" << i + 1 << endl;
        cout << "Please Enter the make: ";
        cin.get();
        getline(cin, cars[i].make);
        cout << "Please Enter tbe year made: ";
        cin >> cars[i].year;
    }
    cout << "Here is your collection:\n";
    for (int j = 0; j < amount; ++j){
        cout << cars[j].year << " " << cars[j].make << endl;
    }
    delete [] cars;
    return 0;
}
