#include <iostream>

using namespace std;

struct Simple
{
    char    a;
    int     b;
    double  c;
};

struct Complex
{
    double f;
    int a[20];
    int *ap;
    Simple s;
    Simple sa[10];
    Simple *sp;
};

int main()
{
    Complex cx;

    cx.a[3] = 10;
    cx.ap = cx.a + 3;
    cout << *cx.ap << endl;

    cx.s.c = 3.14159;
    cx.sa[5].a = 'A';
    cx.sp = cx.sa + 5;
    cout << cx.sp->a << endl;

    return 0;
}
