#include "counter.h"
#include <iostream>
using namespace std;

void Counter::reset() {
    cnt = 0;
}

int Counter::get() const {
    return cnt;
}

void Counter::incr() {
    cnt++;
}
