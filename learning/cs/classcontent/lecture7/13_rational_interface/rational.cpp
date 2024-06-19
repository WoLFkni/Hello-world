#include <cassert>
#include <iostream>
#include "rational.h"

using namespace std;


static int gcd(int x, int y) {
    int r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}


// Rational Numbers
Rational::Rational()
    : num(0), den(1)
{ }

Rational::Rational(int n, int d)
    : num(n), den(d)
{
    assert(d != 0);
    normalize();
}

int Rational::getNum() const
{  return num;  }

int Rational::getDen() const
{  return den;  }

Rational Rational::add(const Rational& r) const
{
    int rnum = num * r.getDen() + den * r.getNum();
    int rden = den * r.getDen();

    return Rational(rnum, rden);
}

Rational Rational::sub(const Rational& r) const
{
    int rnum = num * r.getDen() - den * r.getNum();
    int rden = den * r.getDen();

    return Rational(rnum, rden);
}

Rational Rational::mult(const Rational& r) const
{
    int rnum = num * r.getNum();
    int rden = den * r.getDen();

    return Rational(rnum, rden);
}

Rational Rational::div(const Rational& r) const
{
    int rnum = num * r.getDen();
    int rden = den * r.getNum();

    return Rational(rnum, rden);
}

void Rational::print() const
{
    cout << num << "/" << den << endl;
}

void Rational::normalize() {
    int r = gcd(abs(num), abs(den));
    num /= r;
    den /= r;
}


// Overloaded Operators
Rational operator+(const Rational& r1, const Rational& r2)
{
    return r1.add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    return r1.sub(r2);
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    return r1.mult(r2);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    return r1.div(r2);
}

bool operator==(const Rational& r1, const Rational& r2)
{
    return r1.getDen() == r2.getDen() && r1.getNum() == r2.getNum();
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    return !(r1 == r2);
}

ostream& operator<<(ostream& os, const Rational& r)
{
    os << r.getNum() << "/" << r.getDen();
    return os;
}
