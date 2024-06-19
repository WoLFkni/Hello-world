#include "clock.h"

// Default Constructor
Clock::Clock() {}

// Set initial seconds
Clock::Clock(int seconds) : secs(seconds) {}

// Reset the clock
void Clock::reset_clock() {
    secs.reset();
}

// Increase time by a second
void Clock::incr_second() {
    secs.incr();
}

// Get the current hour
int Clock::get_hour() {
    int s = secs.get();
    return (s/(60*60))%24;
}

// Get the current minute
int Clock::get_minute() {
    int s = secs.get();
    return (s/60)%60;
}

// Get the current second
int Clock::get_second() {
    int s = secs.get();
    return s%60;
}
