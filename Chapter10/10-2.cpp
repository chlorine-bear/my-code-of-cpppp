#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname;       // Person's last name
    char fname[LIMIT];  // Person's first name
public:
    Person() {lname = ""; fname[0] = '\0';};                // #1
    Person(const string & ln, const char * fn = "Heyyou");  // #2
    void Show() const;
    void FormalShow() const;
    ~Person();
};

//Person::Person() {}
Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    cout << fname << ' ' << lname << '\n';
}

void Person::FormalShow() const
{
    cout << lname << ' ' << fname << '\n';
}

Person::~Person() {}

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");

    one.Show();
    one.FormalShow();
    two.Show();
    two.FormalShow();
    three.Show();
    three.FormalShow();

    return 0;
}