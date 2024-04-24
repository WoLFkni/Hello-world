#include <iostream>
#include "counter.h"
using namespace std;

int main()
{
    int n;
    cin >> n;

    reset_counter();
    for (int i = 0; i < n; i++)
        incr_counter();
    cout << "The value of the counter is: " << get_counter() << endl;

    return 0;
}
