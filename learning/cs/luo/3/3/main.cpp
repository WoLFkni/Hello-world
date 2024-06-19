#include <iostream>

using namespace std;

bool check(int n){
    bool flag = true;
    int n0 = n;
    int n1 = 0;
    while (n0>0){
        n1 = n1*10 + n0%10;
        n0 /= 10;
    }
    return n==n1;
}


int main()
{
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++){
        int N;
        cin >> N;
        if (check(N)){
            cout << "Yes" << endl;
            continue;
        }
        if (N<100){
            if (N % 10 == 0){
                cout << "No" << endl;
                continue;
            }
            else {
                cout << "Yes" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}
