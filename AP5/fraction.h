#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction{

    private:
        
        long numerator;
        long denominator;

    public:

        Fraction(long numerator = 0, long denominator = 1);

        Fraction operator-() const;
        Fraction& operator--();
        Fraction& operator++();
        Fraction& operator+=(const Fraction& frac);
        Fraction& operator-=(const Fraction& frac);
        Fraction& operator*=(const Fraction& frac);
        Fraction& operator/=(const Fraction& frac);

        long get_numerator() const;
        long get_denominator() const;

        friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
        friend std::istream& operator>>(std::istream& is, Fraction& frac);

        Fraction operator+(long value);
        Fraction operator-(long value);
        Fraction operator*(long value);
        Fraction operator/(long value);

        friend Fraction operator+(long value, const Fraction& frac);
        friend Fraction operator-(long value, const Fraction& frac);
        friend Fraction operator*(long value, const Fraction& frac);
        friend Fraction operator/(long value, const Fraction& frac);

};

inline long Fraction::get_numerator() const{
    return numerator;
}

inline long Fraction::get_denominator() const{
    return denominator;
}

#endif