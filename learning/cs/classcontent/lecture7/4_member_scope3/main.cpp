#include <iostream>

using namespace std;

class Foo {
public:
    void init(int v) { i = v; }

    void print() const {
        for (int j = 0; j < 3; j++)
            cout << i << endl;
    }
private:
    int i;
};

int main() {
    Foo f;
    f.init(10);
    f.print();
    return 0;
}
