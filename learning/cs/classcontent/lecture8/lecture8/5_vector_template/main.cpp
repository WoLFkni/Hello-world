#include <iostream>
#include "Vector.h"
using namespace std;

template<class T>
void printVector(Vector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    Vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.add(i);

    cout << "Size of Vector: " << vec.size() << endl;
    printVector(vec);

    Vector<string> vs;
    vs.add("hello");
    vs.add("my");
    vs.add("friend");
    printVector(vs);

    vs.remove(1);
    vs.insert(1, "our");
    vs.insert(2, "good");
    printVector(vs);

    return 0;
}
