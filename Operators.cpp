#include "Fraction.h"
#include <iostream>

int greatest_common_divisor(int a, int b) //наибольший общий делитель
{
    return (b == 0) ? (a > 0 ? a : -a) : greatest_common_divisor(b, a % b); //Euclidean algorithm
}

int least_common_multiple (int a, int b)  //наименьшее общее кратное
{
    return (a * b) / greatest_common_divisor (a,b);
}

std::ostream& operator<< (std::ostream& out, const Fraction& f)
{
    out << f.get_numerator() << "/" << f.get_denominator();
    return out;
}

Fraction new_fraction_from_revers(const Fraction& f)
{
    return Fraction(f.get_denominator(), f.get_numerator(),true);
}


Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    if (f1.get_denominator() == f2.get_denominator())
    {
        return Fraction (f1.get_numerator() + f2.get_numerator(), f1.get_denominator());
    }
    else
    {
        int lcm = least_common_multiple(f1.get_denominator(), f2.get_denominator());
        Fraction(lcm / f1.get_denominator() * f1.get_numerator(), lcm, false) + Fraction(lcm / f2.get_denominator() * f2.get_numerator(), lcm, false);
    }
}

Fraction operator+(const Fraction& f, int value)
{
    return f + Fraction(value * f.get_denominator(), f.get_denominator());
}


Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.get_numerator() * f1.get_numerator(), f2.get_denominator() * f2.get_denominator());
}

Fraction operator*(const Fraction& f, int value)
{
    return Fraction(f.get_numerator() * value, f.get_denominator());
}

Fraction operator*(int value, const Fraction& f)
{
    return Fraction(f.get_numerator() * value, f.get_denominator());
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1 * new_fraction_from_revers(f2));
}

Fraction operator/(const Fraction& f, int value)
{
    return Fraction(f.get_numerator(), f.get_denominator() * value);
}

Fraction operator/(int value, const Fraction& f)
{
    return new_fraction_from_revers(f) * value;
}
