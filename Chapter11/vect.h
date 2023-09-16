#ifndef EFFC79DD_1D93_44E6_B427_A9EA0E93B86E
#define EFFC79DD_1D93_44E6_B427_A9EA0E93B86E
#include <iostream>
#include <cmath>

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    class Vector
    {
    public:
        enum Mode {RECT, POL};

    private:
        double x;
        double y;
        //double mag;
        //double ang;
        Mode mode;

        /* void set_pol()
        {
            mag = std::sqrt(x * x + y * y);
            ang = x || y ? std::atan2(y, x) : 0;
        }

        void set_rect()
        {
            x = mag * std::cos(ang);
            y = mag * std::sin(ang);
        } */

    public:
        Vector()
        {
            x = y /* = mag = ang */ = 0;
            mode = RECT;
        }

        Vector(double n1, double n2, Mode form = RECT)
        {
            switch (form)
            {
            case RECT:
                x = n1;
                y = n2;
                // set_pol();
                mode = RECT;
                break;
            
            case POL:
                /* mag = n1;
                ang = n2 / Rad_to_deg;
                set_rect(); */
                x = n1 * cos(n2 / Rad_to_deg);
                y = n1 * sin(n2 / Rad_to_deg);
                mode = POL;
                break;

            default:
                std::cout << "Incorrect 3rd argument -- "
                          << "vector set to 0.\n";
                x = y /* = mag = ang */ = 0;
                mode = RECT;
                break;
            }
        }

        void reset(double n1, double n2, Mode form = RECT)
        {
            switch (form)
            {
            case RECT:
                x = n1;
                y = n2;
                //set_pol();
                mode = RECT;
                break;
            
            case POL:
                /* mag = n1;
                ang = n2 / Rad_to_deg;
                set_rect(); */
                x = n1 * cos(n2 / Rad_to_deg);
                y = n1 * sin(n2 / Rad_to_deg);
                mode = POL;
                break;

            default:
                std::cout << "Incorrect 3rd argument -- "
                          << "vector set to 0.\n";
                x = y /* = mag = ang */ = 0;
                mode = RECT;
                break;
            }
        }

        ~Vector(){};

        double xval() const {return x;}
        double yval() const {return y;}

        double magval() const
        {
            return /* mag */ sqrt(x * x + y * y);
        }

        double angval() const
        {
            return /* ang */ x || y ? std::atan2(y, x) : 0;
        }

        void polar_mode() {mode = POL;}
        void rect_mode() {mode = RECT;}

        Vector operator+(const Vector & b) const
        {
            return Vector(x + b.x, y + b.y);
        }

        Vector operator-(const Vector & b) const
        {
            return Vector(x - b.x, y - b.y);
        }

        Vector operator-() const
        {
            return Vector(-x, -y);
        }

        Vector operator*(double n) const
        {
            return Vector(n * x, n * y);
        }

        friend Vector operator*(double, const Vector &);
        friend std::ostream & operator<<(std::ostream &, const Vector &);
    };

    Vector operator*(double n, const Vector & a)
    {
        return Vector(n * a.x, n * a.x);
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        switch (v.mode)
        {
        case Vector::RECT:
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
            break;
        default:
            // os << "(m, a) = (" << v.mag << ", " << (v.ang * Rad_to_deg) << ")";
            os << "(m, a) = (" << v.magval() << ", " << (v.angval() * Rad_to_deg) << ")";
            break;
        }
        return os;
    }
}

#endif /* EFFC79DD_1D93_44E6_B427_A9EA0E93B86E */
