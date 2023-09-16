#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 20;

class Plorg
{
private:
    char m_name[LEN];
    int m_CI;
public:
    Plorg(const char name[] = "Plorga", int CI = 50): m_CI(CI)
    {
        strcpy(m_name, name);
    }
    ~Plorg() {};

    void newCI(int CI = 50);
    void show() const;
};

void Plorg::newCI(int CI)
{
    m_CI = CI;
}

void Plorg::show() const
{
    cout << "Name: " << m_name << '\n'
         << "CI:   " << m_CI << '\n';
}

int main()
{
    Plorg pl("MyPlorg");
    pl.show();
    pl.newCI(250);
    pl.show();
    return 0;
}