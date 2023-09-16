#include <iostream>
#include <cstring>
using namespace std;

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(): selections(0), playtime(0) {performers[0] = label[0] = 0;}

    Cd(const char * s1, const char * s2, int n, double x):
        selections(n), playtime(x)
    {
        strcpy(performers, s1);
        strcpy(label, s2);
    }

    Cd(const Cd & d): selections(d.selections), playtime(d.playtime)
    {
        strcpy(performers, d.performers);
        strcpy(label, d.label);
    }

    virtual ~Cd() {}

    virtual void Report() const
    {
        cout << "Performers: " << performers << '\n'
             << "Label: " << label << '\n'
             << "Selections: " << selections << '\n'
             << "Playtime: " << playtime << '\n';
    }

    virtual Cd & operator=(const Cd & d)
    {
        selections = d.selections;
        playtime = d.playtime;
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        return *this;
    }
};

class Classic : public Cd
{
private:
    char * mainprod;
public:
    Classic(): mainprod(nullptr), Cd() {}

    Classic(const char * mp, const char * s1, const char * s2, int n, double x):
        Cd(s1, s2, n, x)
    {
        mainprod = new char[strlen(mp) + 1];
        strcpy(mainprod, mp);
    }

    Classic(const Classic & c): Cd(c)
    {
        mainprod = new char[strlen(c.mainprod) + 1];
        strcpy(mainprod, c.mainprod);
    }

    ~Classic()
    {
        delete [] mainprod;
        mainprod = nullptr;
    }

    Classic & operator=(const Classic & c)
    {
        
        Cd temp();
        delete [] mainprod;
        mainprod = new char[strlen(c.mainprod) + 1];
        strcpy(mainprod, c.mainprod);
        return *this;
    }

    void Report() const
    {
        Cd::Report();
        cout << "Main Product: " << mainprod << '\n';
    }
};

void Bravo(const Cd & disk) {disk.Report();}

int main(int argc, char const *argv[])
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;

    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment:\n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}
