#include "counter.h"
#include <iostream>
using namespace std;

Counter::Counter()
    : cnt(0)
{}

Counter::Counter(int n)
    : cnt(n)
{}

void Counter::reset() {
    cnt = 0;
}

int Counter::get() const {
    return cnt;
}

void Counter::incr() {
    cnt++;
}
