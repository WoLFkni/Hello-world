/* A clock library that counts the time in 24 hours */

#include "counter.h"

// Reset the clock
void reset_clock()
{
    reset_counter();
}

// Increase time by a second
void incr_second()
{
    incr_counter();
}

// Get the current hour
int get_hour()
{
    int s = get_counter();
    return (s/(60*60))%24;
}

// Get the current minute
int get_minute()
{
    int s = get_counter();
    return (s/60)%60;
}

// Get the current second
int get_second()
{
    int s = get_counter();
    return s%60;
}
