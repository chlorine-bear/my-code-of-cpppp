#include <iostream>
#include <cstring>
using namespace std;
const int Len = 40;

class golf
{
private:
    char fullname[Len];
    int handicap_;
public:
    golf();
    ~golf();
    void setgolf(const char *, int);
    int setgolf();
    void handicap(int);
    void showgolf();
};

golf::golf()
{
    fullname[0] = '\0';
    handicap_ = 0;
}

golf::~golf() {}

void golf::setgolf(const char * name, int hc)
{
    strcpy(fullname, name);
    handicap_ = hc;
}

int golf::setgolf()
{
    cout << "Please enter the fullname: ";
    cin.getline(fullname, Len);
    cout << "Please enter the handicap: ";
    (cin >> handicap_).get();
    return fullname[0] != '\0';
}

void golf::handicap(int hc)
{
    handicap_ = hc;
}

void golf::showgolf()
{
    cout << "Fullname: " << fullname << '\n'
         << "Handicap: " << handicap_ << '\n';
}

int main()
{
    int amount, realnum = 0;
    cout << "Enter the amount of golf list: ";
    (cin >> amount).get();
    golf * glist = new golf[amount];

    for (int i = 0; i < amount; ++i)
    {
        cout << "No." << (i + 1) << '\n';
        if (glist[i].setgolf())
        {
            ++realnum;
            continue;
        }
        break;
    }
    
    char tempfn[Len];
    int temphc;
    for (int i = 0; i < realnum; ++i)
    {
        cout << "No." << (i + 1) << '\n'
             << "Revalue the fullname: ";
        cin.getline(tempfn, Len);
        glist[i].setgolf(tempfn, 0);
        cout << "Revalue the handicap: ";
        (cin >> temphc).get();
        glist[i].handicap(temphc);
    }

    for (int i = 0; i < realnum; ++i)
    {
        cout << "No." << (i + 1) << '\n';
        glist[i].showgolf();
    }

    delete [] glist;
    return 0;
}