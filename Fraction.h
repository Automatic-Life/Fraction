#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction (int numerator=0, int denominator=1, bool reduse=true):
        m_numerator(numerator), m_denominator(denominator)
    {
        if (reduse) {reduce_fraction();}
    }

    int get_numerator() const {return m_numerator;}
    int get_denominator() const {return m_denominator;}

    void reverse_fraction();

    void reduce_fraction();


};


int greatest_common_divisor(int a, int b);
int least_common_multiple (int a, int b);

std::ostream& operator<< (std::ostream& out, const Fraction& f);
Fraction new_fraction_from_revers(const Fraction& f);

Fraction operator+(const Fraction& f1, const Fraction& f2);
Fraction operator+(const Fraction& f, int value);
Fraction operator*(const Fraction& f1, const Fraction& f2);
Fraction operator*(const Fraction& f, int value);
Fraction operator*(int value, const Fraction& f);
Fraction operator/(const Fraction& f1, const Fraction& f2);
Fraction operator/(const Fraction& f, int value);
Fraction operator/(int value, const Fraction& f);


#endif // FRACTION_H_INCLUDED
