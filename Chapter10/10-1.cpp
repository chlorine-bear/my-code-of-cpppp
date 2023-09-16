#include <iostream>
#include <string>
using namespace std;

class bank_account
{
private:
    string m_name;
    string m_account;
    int m_money;
public:
    bank_account(string name = "", string account = "", int money = 0);
    ~bank_account();
    void show();
    void save_money(int money = 0);
    bool get_money(int money = 0);
};

bank_account::bank_account(string name, string account, int money):
    m_name(name), m_account(account), m_money(money) {}

bank_account::~bank_account() {}

void bank_account::show()
{
    cout << "Name:    " << m_name << "\n"
         << "Account: " << m_account << "\n"
         << "Money:   " << m_money << "\n";
}

void bank_account::save_money(int money)
{
    m_money += money;
}

bool bank_account::get_money(int money)
{
    if (m_money < money)
        return false;
    m_money -= money;
    return true;
}


int main()
{
    bank_account account1("Tiansuo Hao'er", "1145141919810", 0);
    account1.show();
    account1.save_money(114514);
    account1.show();
    account1.get_money(191981);
    account1.show();
    account1.get_money(810);
    account1.show();
    return 0;
}