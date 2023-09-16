#include <iostream>
#include <cstring>
using namespace std;

class Cow
{
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char *, const char *, double);
    Cow(const Cow &);
    ~Cow();
    Cow & operator=(const Cow &);
    void showCow() const;
};

Cow::Cow(): weight(0), hobby(nullptr)
{
    name[0] = '\0';
}

Cow::Cow(const char * n, const char * h, double w): weight(w)
{
    strcpy(name, n);
    hobby = new char[strlen(h) + 1];
    strcpy(hobby, h);
}

Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    name[0] = '\0';
    delete [] hobby;
    weight = 0;
}

Cow & Cow::operator=(const Cow & c)
{
    if (this != &c)
    {
        strcpy(name, c.name);
        delete [] hobby;
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
        weight = c.weight;
    }
    return *this;
}

void Cow::showCow() const
{
    cout << "Name:   " << name << '\n'
         << "Hobby:  " << hobby << '\n'
         << "Weight: " << weight << '\n';
}

int main()
{
    Cow cow1;
    Cow cow2("Lovely", "Sleepy", 114.514);
    Cow cow3(cow2);
    cow1 = cow2;

    cow1.showCow();
    cow2.showCow();
    cow3.showCow();
}