#include <iostream>

namespace SALES
{
    const int QUARTERS = 4;

    class Sales
    {
    private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales();
        ~Sales();
        void setSales(const double [], int);
        void setSales();
        void showSales() const;
    };
    
    Sales::Sales() {}
    Sales::~Sales() {}

    void Sales::setSales(const double ar[], int n)
    {
        int minSize = QUARTERS < n ? 4 : n;
        for (int i = n; i < QUARTERS; ++i)
            sales[i] = 0;
        
        double maxN = ar[0], minN = ar[0], sum = ar[0];
        sales[0] = ar[0];
        for (int i = 1; i < minSize; ++i)
        {
            sales[i] =  ar[i];
            maxN = maxN > ar[i] ? maxN : ar[i];
            minN = minN < ar[i] ? minN : ar[i];
            sum += sales[i];
        }

        max = maxN;
        min = minN;
        average = sum / minSize;
    }

    void Sales::setSales()
    {
        double s[QUARTERS];
        for (int i = 0; i < QUARTERS; ++i)
        {
            std::cout << "Enter the sale of Quarter " << (i + 1) << ": ";
            std::cin >> s[i];
        }
        Sales::setSales(s, QUARTERS);
    }

    void Sales::showSales() const
    {
        for (int i = 0; i < QUARTERS; ++i)
            std::cout << "Sale of Quarter " << (i + 1) << ": "
                      << sales[i] << '\n';
        std::cout << "The average: " << average << '\n';
        std::cout << "The maximum: " << max << '\n';
        std::cout << "The minimum: " << min << '\n';
    }
}

int main()
{
    double slist[3] {956.6, 159.4, 132.8};
    SALES::Sales s1, s2;
    
    s1.setSales(slist, 3);
    s2.setSales();

    s1.showSales();
    s2.showSales();

    return 0;
}