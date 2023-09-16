#ifndef C8C57FE2_627D_4457_8432_28CE008F7147
#define C8C57FE2_627D_4457_8432_28CE008F7147
#include <iostream>
#include <cmath>

class complex
{
private:
    double m_re;    // 实部
    double m_im;    // 虚部
public:
    /*构造函数*/
    // 默认构造函数
    complex(): m_re(0), m_im(0) {}
    // 带参数构造函数
    complex(const double re, const double im = 0): m_re(re), m_im(im) {}
    // 拷贝构造函数（弃用）
    //complex(const complex & c): m_re(c.m_re), m_im(c.m_im) {}
    /*为对象重新赋值*/
    void revalue(const double re = 0, const double im = 0)
    {
        m_re = re;
        m_im = im;
    }
    ~complex() {}   // 默认析构函数

    /*复共轭函数*/
    // 返回该对象的复共轭，但不改变该对象
    complex operator~() const
    {
        complex ans(m_re, - m_im);
        return ans;
    }
    // 将该对象更改为复共轭，并返回
    complex conj()
    {
        m_im = - m_im;
        return *this;
    }
    /*返回对象的相反数*/
    complex operator-() const
    {
        complex ans(- m_re, - m_im);
        return ans;
    }

    double & re() {return m_re;}    // 返回该对象实部的引用
    double & im() {return m_im;}    // 返回该对象虚部的引用

    /*返回该对象到原点的距离（模长）的平方*/
    double dist() const
    {
        return m_im * m_im + m_re * m_re;
    }

    /*将两个复数相加，返回结果*/
    complex operator+(const complex & b) const
    {
        complex ans(m_re + b.m_re, m_im + b.m_im);
        return ans;
    }
    /*将两个复数相加，并赋值给前一个复数*/
    complex operator+=(const complex & b)
    {
        m_re += b.m_re;
        m_im += b.m_im;
        return *this;
    }

    /*将两个复数相减，返回结果*/
    complex operator-(const complex & b) const
    {
        complex ans(m_re - b.m_re, m_im - b.m_im);
        return ans;
    }
    /*将两个复数相减，并赋值给被减数*/
    complex operator-=(const complex & b)
    {
        m_re -= b.m_re;
        m_im -= b.m_im;
        return *this;
    }

    /*将两个复数相乘，返回结果*/
    complex operator*(const complex & b) const
    {
        complex ans
        (
            m_re * b.m_re - m_im * b.m_im,
            m_re * b.m_im + m_im * b.m_re
        );
        return ans;
    }
    /*将两个复数相乘，并赋值给前一个复数*/
    complex operator*=(const complex & b)
    {
        m_re = m_re * b.m_re - m_im * b.m_im;
        m_im = m_re * b.m_im + m_im * b.m_re;
        return *this;
    }

    /*将复数与一个实数相乘，返回结果*/
    complex operator*(const double x) const
    {
        complex ans(x * m_re, x * m_im);
        return ans;
    }
    /*将复数与一个实数相乘，并赋值给该复数*/
    complex operator*=(const double x)
    {
        m_re *= x;
        m_im *= x;
        return *this;
    }

    /*用一个实数除复数，返回结果*/
    complex operator/(const double x) const
    {
        if (x == 0)
            return *this;   // 如果实数为0，直接返回自身
        else
        {
            complex ans(m_re / x, m_im / x);
            return ans;
        }
    }
    /*用一个实数除复数，并赋值给该复数*/
    complex operator/=(const double x)
    {
        if (x != 0) // 如果实数为0，不进行操作
        {
            m_re /= x;
            m_im /= x;
        }
        return *this;
    }

    /*返回该复数对应的模长为1的复数（复平面上的单位向量）*/
    // 如果复数为0，则返回复数0
    complex unit() const
    {
        return dist() == 0 ? *this : *this / sqrt(dist());
    }

    /*将两个复数相除，返回结果*/
    complex operator/(const complex & b) const
    {
        if (b.dist() != 0)
        {
            complex temp = (*this) * (~b);
            return temp / b.dist();
        }
        else
            return *this;   // 如果除数为0，直接返回被除数
    }
    /*将两个复数相除，并赋值给被除数*/
    complex operator/=(const complex & b)
    {
        if (b.dist() != 0)
        {
            m_re = (m_re * b.m_re + m_im * b.m_im) / b.dist();
            m_im = (m_im * b.m_re - m_re * b.m_im) / b.dist();
        }
        return *this;   // 如果除数为0，不修改被除数
    }

    /*判断两个复数是否相等*/
    bool operator==(const complex & b) const
    {
        return (m_re == b.m_re) && (m_im == b.m_im);
    }
    /*判断两个复数是否不相等*/
    bool operator!=(const complex & b) const
    {
        return ! (*this == b);
    }

    friend complex operator*(const double, const complex &);
    friend std::ostream & operator<<(std::ostream &, const complex &);
    friend std::istream & operator>>(std::istream &, complex &);
};

/*友元：将实数与一个复数相乘，返回结果*/
complex operator*(const double x, const complex & c)
{
    return c * x;
}

/*友元：std::ostream，用于输出*/
std::ostream & operator<<(std::ostream & os, const complex & c)
{
    return os << "(" << c.m_re << ", " << c.m_im << "i)";
}

/*友元：std::istream，用于输入*/
std::istream & operator>>(std::istream & ins, complex & c)
{
    std::cout << "real: ";
    ins >> c.m_re;
    std::cout << "imaginary: ";
    ins >> c.m_im;
    return ins;
}

#endif /* C8C57FE2_627D_4457_8432_28CE008F7147 */
