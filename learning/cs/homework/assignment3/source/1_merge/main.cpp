#include <iostream>
#include <vector.h>
#include <sstream>
#include <queue.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    Vector<int> v1(n,0);
    Vector<int> v2(m,0);
    Queue<int> q0;

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    istringstream iss1(s1);
    istringstream iss2(s2);

    for (int i = 0; i < n; i++){
        iss1 >> v1[i];
    }
    for (int i = 0; i < m; i++){
        iss2 >> v2[i];
    }

    int p = 0;
    int q = 0;
    while (p < n || q < m){
        if (p == n ){
            for (int i = q; i < m; i++){
                q0.enqueue(v2[i]);
            }
            break;
        }else if (q == m){
            for (int i = p; i < n; i++){
                q0.enqueue(v1[i]);
            }
            break;
        }
        if (v1[p] <= v2 [q]){
            q0.enqueue(v1[p]);
            p += 1;
        }else{
            q0.enqueue(v2[q]);
            q += 1;
        }
    }
    while (!q0.isEmpty()){
        cout << q0.dequeue() << " ";
    }
    cout << "";
    return 0;
}
