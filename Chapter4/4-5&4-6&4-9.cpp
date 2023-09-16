#include <iostream>
#include <string>
using namespace std;
struct CandyBar{
    string name;
    double weight;
    int heat;
};
int main(){
    CandyBar snack{
        "Mocha Munch",
        2.3,
        350
    };
    cout << snack.name << " " << snack.weight << " " << snack.heat
        << "\n-Task of 4.5.\n";
    CandyBar candylist[3]{
        {"TianSuo", 114.514, 666},
        {"HaoEr", 191.9, 233},
        {"XianBei", 810, 888}
    };
    for (int i = 0; i < 3; i++){
        cout << candylist[i].name << " " << candylist[i].weight << " " << candylist[i].heat << endl;
    }
    cout << "-Task of 4.6.\n";
    CandyBar * ps = new CandyBar [3];
    ps[0] = {"TianSuo", 114.514, 666};
    ps[1] = {"HaoEr", 191.9, 233};
    ps[2] = {"XianBei", 810, 888};
    for (int i = 0; i < 3; i++){
        cout << ps[i].name << " " << ps[i].weight << " " << ps[i].heat << endl;
    }
    delete [] ps;
    cout << "-Task of 4.9.\n";
    return 0;
}