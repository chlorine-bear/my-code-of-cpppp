#include <iostream>
int main(){
    using namespace std;
    long long all_pop, us_pop;
    cout << "Enter the world's population: ";
    cin >> all_pop;
    cout << "Enter the population of the US: ";
    cin >> us_pop;
    double part = double(us_pop) / double(all_pop) * 100;
    cout << "The population of the US is " << part << "\% of the world's population.";
    return 0;
}