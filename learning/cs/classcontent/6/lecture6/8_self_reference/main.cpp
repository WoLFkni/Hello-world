#include <iostream>
#include <string>
using namespace std;

struct SRef{
    int a;
    string b;
    SRef *self;
};

int main()
{
    SRef s;
    s.a = 42;
    s.b = "hello";
    s.self = &s;

    SRef *p = &s;
    while (p != nullptr) {
        cout  << p->a << ", " << p->b << endl;
        p = p->self;
    }

    return 0;
}
