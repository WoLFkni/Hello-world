#include <iostream>

using namespace std;

// Counter
class Counter {
public:
    Counter() {}

    Counter(int n) : cnt(n) {}

    void reset() {
        cnt = 0;
    }

    int get() {
        return cnt;
    }

    void incr() {
        cnt++;
    }

private:
    int cnt;
};

// Clock
class Clock {
public:
    // Default Constructor
    Clock() {}

    // Set initial seconds
    Clock(int seconds) : secs(seconds) {}

    // Reset the clock
    void reset_clock() {
        secs.reset();
    }

    // Increase time by a second
    void incr_second() {
        secs.incr();
    }

    // Get the current hour
    int get_hour() {
        int s = secs.get();
        return (s/(60*60))%24;
    }

    // Get the current minute
    int get_minute() {
        int s = secs.get();
        return (s/60)%60;
    }

    // Get the current second
    int get_second() {
        int s = secs.get();
        return s%60;
    }

private:
    Counter secs;
};


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
