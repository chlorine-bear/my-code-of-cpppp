#include <iostream>
#include <string>
using namespace std;
struct pizza{
    string name;
    double size;
    double weight;
};
int main(){
    pizza nice;
    cout << "Enter the name of the company: ";
    getline(cin, nice.name);
    cout << "Enter the size of the pizza: ";
    cin >> nice.size;
    cout << "Enter the weight of the pizza: ";
    cin >> nice.weight;
    cout << nice.name << " " << nice.size << " " << nice.weight
        << "\n-Task of 4.7.\n";
    pizza * ps = new pizza;
    cout << "Enter the size of the pizza: ";
    cin >> ps -> size;
    cin.get();
    cout << "Enter the name of the company: ";
    getline(cin, ps -> name);
    cout << "Enter the weight of the pizza: ";
    cin >> ps -> weight;
    cout << (* ps).name << " " << (* ps).size << " " << (* ps).weight
        << "\n-Task of 4.8.\n";
    delete ps;
    return 0;
}