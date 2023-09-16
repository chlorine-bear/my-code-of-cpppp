#include <iostream>
using namespace std;

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0): x(a), y(b) {};
    void showmove() const;
    Move add(const Move &) const;
    void reset(double a = 0, double b = 0);
    ~Move(){};
};

void Move::showmove() const
{
    cout << "x = " << x << '\n'
         << "y = " << y << '\n';
}

Move Move::add(const Move & m) const
{
    return Move(x + m.x, y + m.y);
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    Move m1(6, 3);
    Move m2(2);
    Move m3 = m2.add(m1);

    m1.showmove();
    m2.showmove();
    m3.showmove();

    m2.reset(1, 6);
    m2.showmove();

    m1.add(m2).showmove();
    return 0;
}