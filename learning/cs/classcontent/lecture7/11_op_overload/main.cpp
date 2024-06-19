#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int gcd(int x, int y) {
    int r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

// Rational Numbers
class Rational {
public:
    Rational()
        : num(0), den(1)
    { }

    Rational(int n, int d)
        : num(n), den(d)
    {
        assert(d != 0);
        normalize();
    }

    int getNum() const
    {  return num;  }

    int getDen() const
    {  return den;  }

    Rational add(const Rational& r) const
    {
        int rnum = num * r.getDen() + den * r.getNum();
        int rden = den * r.getDen();

        return Rational(rnum, rden);
    }

    Rational sub(const Rational& r) const
    {
        int rnum = num * r.getDen() - den * r.getNum();
        int rden = den * r.getDen();

        return Rational(rnum, rden);
    }

    Rational mult(const Rational& r) const
    {
        int rnum = num * r.getNum();
        int rden = den * r.getDen();

        return Rational(rnum, rden);
    }

    Rational div(const Rational& r) const
    {
        int rnum = num * r.getDen();
        int rden = den * r.getNum();

        return Rational(rnum, rden);
    }

    void print() const
    {
        cout << num << "/" << den << endl;
    }

private:
    void normalize() {
        int r = gcd(abs(num), abs(den));
        num /= r;
        den /= r;
    }

    int num, den;
};

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

int main()
{
    Rational r1(2, 3), r2(7, 4), r3;

    r1.print();
    r2.print();
    r3.print();

    r3 = r1 + r2;
    r3.print();

    r3 = r1 - r2;
    r3.print();

    r3 = r1 * r2;
    r3.print();

    r3 = r1 / r2;
    r3.print();

    cout << (r1 == r2) << endl;
    cout << (r1 != r2) << endl;

    return 0;
}
