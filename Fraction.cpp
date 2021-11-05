#include "Fraction.h"
#include <algorithm>

void Fraction::reverse_fraction()
    {
        std::swap (m_numerator, m_denominator);
    }

void Fraction::reduce_fraction()
    {
        int gcd = greatest_common_divisor(m_numerator, m_denominator);
        if (gcd != 1)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }
