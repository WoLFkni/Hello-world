#include <iostream>
#include "clock.h"
using namespace std;

int main()
{
    int n;
    cin >> n;

    Clock clk;
    for (int i = 0; i < n; i++)
        clk.incr_second();

    cout << "The time is " << clk.get_hour() << ":" << clk.get_minute() << ":" << clk.get_second() <<endl;
    return 0;
}
