#include <iostream>
#include <iomanip>
using namespace std;

struct S
{
    char    a;
    int     b;
    double  c;
};

int main()
{
    S y[20], *z;

    z = y;
    z->a = 'A';
    z->b = 99;
    z->c = 3.14159;

    for (int i = 0; i < 20; i++) {
        cout << left
            << "a = " << setw(2) << y[i].a
            << "b = " << setw(15) << y[i].b
            << "c = " << y[i].c << endl;
    }

    return 0;
}
