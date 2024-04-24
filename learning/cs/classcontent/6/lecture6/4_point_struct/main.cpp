#include <iostream>

using namespace std;

// Point structure
struct Point {
    int x;
    int y;
};

void shift(Point &p, int sx, int sy)
{
    p.x += sx;
    p.y += sy;
}

void pshift(Point *p, int sx, int sy)
{
    p->x += sx;
    p->y += sy;
}

int main()
{
    Point p;
    p.x = 10;
    p.y = 20;

    shift(p, 5, 5);

    cout << p.x << " " << p.y << endl;

    Point *p1 = new Point;

    p1->x = 1;
    p1->y = 2;

    pshift(p1, 3, 3);

    cout << p1->x << " " << p1->y << endl;

    delete p1;

    return 0;
}
