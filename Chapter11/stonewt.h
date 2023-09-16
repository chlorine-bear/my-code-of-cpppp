#ifndef A6B4E63F_858B_4707_9D16_B5448835F27C
#define A6B4E63F_858B_4707_9D16_B5448835F27C
#include <iostream>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    enum MODE {STN, LBS};
    int stone;
    double pds_left;
    double pounds;
    MODE mode;
public:
    Stonewt(int stn, double lbs = 0, MODE md = STN)
    {
        stone = stn;
        pds_left = lbs;
        pounds = Lbs_per_stn * stn + lbs;
        mode = md;
    }
    Stonewt(double lbs, MODE md = STN)
    {
        pounds = lbs;
        stone = lbs / Lbs_per_stn;
        pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
        mode = md;
    }
    Stonewt() {Stonewt(0, 0, STN);}
    ~Stonewt() {}

    Stonewt operator+(Stonewt & b)
    {
        double total = pounds + b.pounds;
        Stonewt ans(total);
        return ans;
    }
    void operator+=(Stonewt & b)
    {
        double total = pounds + b.pounds;
        Stonewt ans(total);
        *this = ans;
    }

    Stonewt operator-(Stonewt & b)
    {
        double total = pounds - b.pounds;
        Stonewt ans(total);
        return ans;
    }
    void operator-=(Stonewt & b)
    {
        double total = pounds - b.pounds;
        Stonewt ans(total);
        *this = ans;
    }

    Stonewt operator*(double n)
    {
        Stonewt ans(n * pounds);
        return ans;
    }
    void operator*=(double n)
    {
        Stonewt ans(n * pounds);
        *this = ans;
    }

    bool operator==(Stonewt & b)
    {
        return pounds == b.pounds;
    }
    bool operator!=(Stonewt & b)
    {
        return pounds != b.pounds;
    }

    bool operator>(Stonewt & b)
    {
        return pounds > b.pounds;
    }
    bool operator>=(Stonewt & b)
    {
        return pounds >= b.pounds;
    }

    bool operator<(Stonewt & b)
    {
        return pounds < b.pounds;
    }
    bool operator<=(Stonewt & b)
    {
        return pounds <= b.pounds;
    }

    friend std::ostream & operator<<(std::ostream &, Stonewt &);
    friend Stonewt operator*(double, Stonewt &);
};

std::ostream & operator<<(std::ostream & os, Stonewt & sto)
{
    switch (sto.mode)
    {
    case Stonewt::STN:
        return os << sto.stone << "stone, " << sto.pds_left << "pounds";
    default:
        return os << sto.pounds << "pounds";
    }
}

Stonewt operator*(double n, Stonewt & s)
{
    return s * n;
}

#endif /* A6B4E63F_858B_4707_9D16_B5448835F27C */
