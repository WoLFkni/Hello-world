#include <iostream>
#include <random.h>
using namespace std;

struct IntArray {
    int n;
    int *arr;
};

IntArray createIntArray(int n)
{
    IntArray a;
    a.n = n;
    a.arr = new int[n];
    for (int i = 0; i < n; i++)
        a.arr[i] = 0;
    return a;
}

void deleteIntArray(const IntArray &a)
{
    delete a.arr;
}

bool checkBound(const IntArray &a, int i)
{
    if (i >= a.n) {
        cerr << "Out of bound access: index "
             << i << " into an array of size " << a.n << endl;
        return false;
    }

    return true;
}

bool setIntArray(IntArray& a, int i, int val)
{
    if (!checkBound(a, i))
        return false;

    a.arr[i] = val;
    return true;
}

int getIntArray(const IntArray& a, int i)
{
    if (!checkBound(a, i))
        return 0;

    return a.arr[i];
}

int printIntArray(const IntArray& a)
{
    cout << "[";
    for (int i = 0; i < a.n; i++)
        cout << getIntArray(a, i) << ";";
    cout << "]\n";
}

int fillRandomValues(IntArray& a)
{
    for (int i = 0; i < a.n; i++)
        setIntArray(a, i, randomInteger(1, 100));
}

void copyIntArray(const IntArray &src, IntArray &dst)
{
    int n = src.n;
    dst.n = n;
    dst.arr = new int[n];
    for (int i = 0; i < n; i++)
        dst.arr[i] = src.arr[i];
}

int main()
{
    int n;
    cin >> n;
    IntArray a = createIntArray(n);
    fillRandomValues(a);
    printIntArray(a);

    IntArray b;
    copyIntArray(a, b);
    printIntArray(b);

    deleteIntArray(a);
    deleteIntArray(b);

    return 0;
}
