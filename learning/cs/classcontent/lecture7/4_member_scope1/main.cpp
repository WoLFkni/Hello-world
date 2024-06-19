#include <iostream>

using namespace std;

// Counters
class Counter {
public:
    void incrAndReset() {
       incr();
       reset();
    }

    void reset()
    {  cnt = 0;  }

    void incr()
    {  cnt++;  }

    int get() const
    {  return cnt;  }

private:
    int cnt;
};

int main()
{
    Counter c;
    c.incrAndReset();
    cout << c.get() << endl;

    return 0;
}
