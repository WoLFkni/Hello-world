#include <iostream>
#include <cmath>
#include <cassert>
#include "rational.h"
using namespace std;

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
