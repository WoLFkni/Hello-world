#include <iostream>

using namespace std;

struct S
{
    char    a;
    short   b;
    double  c;
};

struct S1
{
    char    a;
    short   b;
    double  c;
} __attribute((packed))__;

int main()
{
    S s;

    cout << sizeof(s) << endl;
    cout << "Addr of s: " << &s << endl
          << "Addr of s.a: " << (int*)&s.a << endl
          << "Addr of s.b: " << &s.b << endl
          << "Addr of s.c: " << &s.c << endl << endl;

    S1 s1;
    cout << sizeof(s1) << endl;
    cout << "Addr of s1: " << &s1 << endl
          << "Addr of s1.a: " << (int*)&s1.a << endl
          << "Addr of s1.b: " << &s1.b << endl
          << "Addr of s1.c: " << &s1.c << endl << endl;

    return 0;
}
