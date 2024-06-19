#include <iostream>
#include <vector>

using namespace std;

vector<int> v = {1,1,2};

int ele(int n){
    while (v.size() <= n){
        unsigned long long x = 0;
        if (v.size() % 2 == 1){
            x = (v[v.size()/2]*v[v.size()/2])%100000007;
            for (int i = v.size()/2 -1 ; i >= 0; i--){
                x += (2 * (v[i] * v[v.size()-1-i])%100000007);
                x = x%100000007;
            }
            v.push_back(x%100000007);
        }else{
            for (int i = v.size()/2 -1 ; i >= 0; i--){
                x += (2 * (v[i] * v[v.size()-1-i])%100000007);
                x = x%100000007;
            }
            v.push_back(x%100000007);
        }
    }
    return v[n];
}

int main()
{
    int n;
    cin >> n;
    cout << ele(n);
    return 0;
}
