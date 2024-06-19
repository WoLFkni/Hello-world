#include <iostream>

using namespace std;

// Point structure
struct Point {
    int x;
    int y;

    void shift(int sx, int sy)
    {
        x += sx;
        y += sy;
    }
};

int main()
{
    Point p;

    p.x = 1;
    p.y = 2;

    p.shift(3, 5);

    cout << "The coordinate is at (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
