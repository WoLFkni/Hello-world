#include <iostream>
#include "Vector.h"
using namespace std;

void printVector(IVector& vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec.get(i) << " ";
    cout << endl;
}

int main()
{
    IVector vec;
    for (int i = 0; i < 10; i++)
        vec.add(i);

    cout << "Size of Vector: " << vec.size() << endl;
    printVector(vec);
    vec.clear();
    for (int i = 0; i < 10; i++)
        vec.insert(0,i);
    printVector(vec);

    IVector vec1(vec);
    for (int i = 0; i < 20; i++)
        vec1.add(i);
    printVector(vec1);

    vec = vec1;
    printVector(vec);

    return 0;
}
