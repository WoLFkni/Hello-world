#include <iostream>
#include <fstream>
using namespace std;

// Counter
class Counter {
public:
    void reset() {
        cnt = 0;
    }

    int get() {
        return cnt;
    }

    void incr() {
        cnt++;
        log();
    }

private:
    void log()
    {
        ofstream ofs("log.txt");
        ofs << "Counter is " << cnt << endl;
        ofs.close();
    }

    int cnt;
};


int main()
{
    Counter c;
    c.reset();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        c.incr();
    cout << "The value of the counter is: " << c.get() << endl;

    return 0;
}
