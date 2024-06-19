#include <iostream>

using namespace std;

void bubble_sort(int *arr, int n)
{
    for (int k = 0; k < n-1; k++) {
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete [] arr;

    return 0;
}
