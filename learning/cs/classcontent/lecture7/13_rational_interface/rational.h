#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <ostream>

// Rational Numbers
class Rational {
public:
    Rational();

    Rational(int n, int d);

    int getNum() const;
    int getDen() const;

    Rational add(const Rational& r) const;
    Rational sub(const Rational& r) const;
    Rational mult(const Rational& r) const;
    Rational div(const Rational& r) const;

    void print() const;

private:
    void normalize();

    int num, den;
};

// Overloaded Operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

std::ostream& operator<<(std::ostream& os, const Rational& r);

#endif // RATIONAL_H_INCLUDED
