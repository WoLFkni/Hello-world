#include <iostream>
#include "clock.h"

using namespace std;

int main()
{
    int n;
    cin >> n;

    reset_clock(); // Initialize the clock
    for (int i = 0; i < n; i++)
        incr_second();

    cout << "The time is " << get_hour() << ":" << get_minute() << ":" <<get_second() <<endl;
    return 0;
}
