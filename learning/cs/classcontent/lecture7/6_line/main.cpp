#include <iostream>
#include <cmath>
using namespace std;

class Line {
public:
    Line()
        : x1(0), y1(0), x2(0), y2(0)
    { }

    Line(int px1, int py1, int px2, int py2)
        : x1(px1), y1(py1), x2(px2), y2(py2)
    { }

    double getDistance() const
    {
        double d1 = x1 - x2;
        double d2 = y1 - y2;
        return sqrt(d1*d1 + d2*d2);
    }

    void setStartPoint(int px1, int py1)
    {
        x1 = px1;
        y1 = py1;
    }

    void setEndPoint(int px2, int py2)
    {
        x2 = px2;
        y2 = py2;
    }

private:
    double x1, y1, x2, y2;
};


int main()
{
    Line l(0, 0, 3, 4);
    cout << l.getDistance() << endl;
    return 0;
}
