#include <iostream>
using namespace std;

struct Simple
{
    char    a;
    int     b;
    double  c;
};
// Complex embeds Simple
struct Complex
{
    double f;
    int a[3];
    Simple s;
};


int main()
{
    Simple s = {'A', 10, 3.14};

    Complex c = {2.2222, {1, 2, 3}, {'A', 10, 3.14}};

    cout << c.s.c << endl;

    return 0;
}
