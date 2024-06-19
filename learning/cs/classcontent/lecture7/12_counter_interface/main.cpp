#include <iostream>
#include "counter.h"
using namespace std;

int main()
{
    Counter c;
    c.reset();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        c.incr();
    cout << "The value of the counter is: " << c.get() << endl;

    return 0;
}
