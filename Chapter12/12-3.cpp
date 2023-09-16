#include <iostream>
#include "stock20.h"

const int STKS = 4;
int main()
{
    Stock Stocks[STKS]
    {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock hodings:\n";
    for (int i = 0; i < STKS; ++i)
        //Stocks[i].show();
        std::cout << Stocks[i];
    
    const Stock * top = Stocks;
    for (int i = 0; i < STKS; ++i)
        top = &top->topval(Stocks[i]);

    std::cout << "\nMost Valuable Holding:\n";
    //top->show();
    std::cout << *top;
    return 0;
}