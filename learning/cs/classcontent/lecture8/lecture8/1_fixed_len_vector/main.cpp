#include <iostream>
#include <Random.h>
#include "fvector.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    FVector vec(n);

    for (int i = 0; i < vec.size(); i++)
        vec.set(i, randomInteger(1, 100));

    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";

    return 0;
}
