#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

// Counter
class Counter {
public:

    void reset();

    int get() const;

    void incr();

private:
    int cnt;
};

#endif // COUNTER_H_INCLUDED
