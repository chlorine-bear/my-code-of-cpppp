#include<iostream>
#include<string>
using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int heat;
};

void revalue
(
    CandyBar & cb,
    const char strl[] = "Millennium Munch\0",
    const double wt = 2.85,
    const int ht = 350
)
{
    string str(strl);
    cb.name = str;
    cb.weight = wt;
    cb.heat = ht;
}

void show(const CandyBar & cb)
{
    cout << "Name: " << cb.name
         << "\nWeight: " << cb.weight
         << "\nHeat: " << cb.heat << endl;
}

int main()
{
    CandyBar cb1, cb2;
    revalue(cb1);
    show(cb1);

    revalue(cb2, "My CandyBar\0", 114, 514);
    show(cb2);
    return 0;
}