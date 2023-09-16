#ifndef AB2C524F_293C_45A6_920B_35C036CB8FAC
#define AB2C524F_293C_45A6_920B_35C036CB8FAC
#include <iostream>
#include <cstring>

class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}

public:
    Stock(/* args */);
    Stock(const char*, long n = 0, double pr = 0);
    ~Stock();

    void buy(long, double);
    void sell(long, double);
    void update(double);
    void show() const;
    const Stock & topval(const Stock&) const;

    friend std::ostream& operator<<(std::ostream&, const Stock&);
};

Stock::Stock(/* args */)
{
    company = nullptr;
    shares = 0;
    share_val = total_val = 0;
}

Stock::Stock(const char* ch, long n, double pr)
{
    company = new char[std::strlen(ch)];
    strcpy(company, ch);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        n = 0;
    }
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    delete [] company;
    company = nullptr;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can't sell more than you have. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;

    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
         << " Shares: " << shares << '\n';
    cout << " Share Price: &" << share_val ;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock& s) const
{
    return s.total_val > total_val ? s : *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& s)
{
    using std::ios_base;

    ios_base::fmtflags orig = 
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << s.company
       << " Shares: " << s.shares << '\n';
    os << " Share Price: &" << s.share_val ;
    os.precision(2);
    os << " Total Worth: $" << s.total_val << '\n';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

#endif /* AB2C524F_293C_45A6_920B_35C036CB8FAC */
