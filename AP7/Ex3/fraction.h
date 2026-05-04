#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction{

    private:
        
        long numerator;
        long denominator;

    public:

        class DivError{};

        Fraction(long numerator = 0, long denominator = 1) noexcept(false);

        Fraction operator-() const noexcept(true);
        Fraction& operator--() noexcept(true);
        Fraction& operator++() noexcept(true);
        Fraction& operator+=(const Fraction& frac) noexcept(true);
        Fraction& operator-=(const Fraction& frac) noexcept(true);
        Fraction& operator*=(const Fraction& frac) noexcept(true);
        Fraction& operator/=(const Fraction& frac) noexcept(false);

        long get_numerator() const noexcept(true);
        long get_denominator() const noexcept(true);
 
        friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) noexcept(true);
        friend std::istream& operator>>(std::istream& is, Fraction& frac) noexcept(false);

        Fraction operator+(const Fraction& frac) const noexcept(true);
        Fraction operator-(const Fraction& frac) const noexcept(true);
        Fraction operator*(const Fraction& frac) const noexcept(true);
        Fraction operator/(const Fraction& frac) const noexcept(false);

        friend Fraction operator+(long value, const Fraction& frac) noexcept(true);
        friend Fraction operator-(long value, const Fraction& frac) noexcept(true);
        friend Fraction operator*(long value, const Fraction& frac) noexcept(true);
        friend Fraction operator/(long value, const Fraction& frac) noexcept(true);

};

inline long Fraction::get_numerator() const noexcept {
    return numerator;
}

inline long Fraction::get_denominator() const noexcept {
    return denominator;
}

#endif