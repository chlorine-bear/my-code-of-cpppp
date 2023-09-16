#ifndef B1932DF8_8336_4457_8509_E0690D258702
#define B1932DF8_8336_4457_8509_E0690D258702
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;

public:
    Time(): hours(0), minutes(0) {}
    Time(int h, int m): hours(h), minutes(m) {}
    ~Time() {}

    void AddMin(int m)
    {
        minutes += m;
        hours += minutes / 60;
        minutes %= 60;
    }
    void AddHr(int h) {hours += h;}

    void Reset(int h = 0, int m = 0)
    {
        hours = h;
        minutes = m;
    }

    friend Time operator+(const Time &, const Time &);
    friend Time operator-(const Time &, const Time &);
    friend Time operator*(const Time &, double);
    friend Time operator*(double, const Time &);
    friend std::ostream & operator<<(std::ostream &, const Time &);
};

Time operator+(const Time & a, const Time & b)
{
    Time sum;
    sum.minutes = a.minutes + b.minutes;
    sum.hours = a.hours + b.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time & a, const Time & b)
{
    Time diff;
    int tot1 = b.minutes + 60 * b.hours,
        tot2 = a.minutes + 60 * a.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(const Time & t, double n)
{
    Time ans;
    long tot = n * (t.minutes + 60 * t.hours);
    ans.minutes = tot % 60;
    ans.hours = tot / 60;
    return ans;
}
Time operator*(double n, const Time & t)
{
    return t * n;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    return os << t.hours << " hours, " << t.minutes << " minutes";
}

#endif /* B1932DF8_8336_4457_8509_E0690D258702 */
