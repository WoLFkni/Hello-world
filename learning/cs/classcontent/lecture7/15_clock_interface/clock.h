#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include "Counter.h"

// Clock
class Clock {
public:
    // Default Constructor
    Clock();

    // Set initial seconds
    Clock(int seconds);

    // Reset the clock
    void reset_clock();

    // Increase time by a second
    void incr_second();

    // Get the current hour
    int get_hour();

    // Get the current minute
    int get_minute();

    // Get the current second
    int get_second();

private:
    Counter secs;
};

#endif // CLOCK_H_INCLUDED
