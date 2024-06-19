#include <iostream>
#include <Random.h>
#include "fvector.h"
using namespace std;

void printFVec(const FVector& vec)
{
    for (int i = 0; i < vec.length(); i++)
        cout << vec.at(i) << " ";
    cout <<endl;
}

void test()
{
    FVector vec(5);

    for (int i = 0; i < vec.length(); i++)
        vec.set(i, randomInteger(1, 100));

    FVector vec1(3);
    vec1 = vec;
    printFVec(vec1);

    FVector vec2(vec);
    printFVec(vec2);
}

int main()
{
    test();
    return 0;
}
