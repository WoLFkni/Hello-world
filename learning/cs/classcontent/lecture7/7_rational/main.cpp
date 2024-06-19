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
    int num, den;
};

int main()
{
    Rational r1(2, 3), r2(7, 4), r3;

    r1.print();
    r2.print();
    r3.print();

    r3 = r1.add(r2);
    r3.print();

    r3 = r1.sub(r2);
    r3.print();

    r3 = r1.mult(r2);
    r3.print();

    r3 = r1.div(r2);
    r3.print();

    return 0;
}
