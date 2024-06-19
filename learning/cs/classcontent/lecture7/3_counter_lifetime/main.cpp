#include <iostream>

using namespace std;

// Counter
class Counter {
public:
    ~Counter()
    {
        cout << "Destructed!" << endl;
    }


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


void incrCounter(int n, Counter c)
{
    if (n > 0) {
        c.incr();
        incrCounter(n-1, c);
    } else
        cout << "The value of the counter is: "
              << c.get() << endl;
}

int main()
{
    Counter c;
    c.reset();

    int n;
    cin >> n;
    incrCounter(n, c);

    return 0;
}
