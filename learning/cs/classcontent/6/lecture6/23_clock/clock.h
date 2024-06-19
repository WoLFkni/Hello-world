#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

/* A clock library that counts the time in 24 hours */

// Reset the clock;
void reset_clock();

// Increase time by a second
void incr_second();

// Get the current hour
int get_hour();

// Get the current minute
int get_minute();

// Get the current second
int get_second();

#endif // CLOCK_H_INCLUDED
