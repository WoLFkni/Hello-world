#include <iostream>

using namespace std;

int a = 10;

class Foo {
public:
    void init(int v) { b = v; }

    void print() const
    { cout << a << endl; }

private:
    int b;
};

int main() {
    Foo f;
    f.init(3);
    f.print();
    return 0;
}

