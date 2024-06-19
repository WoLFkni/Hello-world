#include <iostream>
#include <Random.h>
#include "fvector.h"
using namespace std;

void test()
{
    FVector vec(5);

    for (int i = 0; i < vec.length(); i++)
        vec.set(i, randomInteger(1, 100));

    FVector vec1(3);
    vec1 = vec;
}

int main()
{
    test();
    return 0;
}
