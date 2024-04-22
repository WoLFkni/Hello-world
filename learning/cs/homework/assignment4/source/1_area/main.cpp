#include <iostream>

using namespace std;

const size_t MAX_SIZE = 102;

/*给出每个⽹格上⻓⽅体的⾼度，即每个⽹格上的⻓⽅体由多少个立⽅体搭建⽽成，要求这个三维模型的表⾯积是多少*/
int main()
{
    int model[MAX_SIZE][MAX_SIZE] = {}; // 初始化二维数组为全0
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> model[i][j];
        }
    }
    int area = 2*n*m;
    for (int i = 0; i < n; i++){
        int *p = model[i];
        area += *p;
        for (int j = 0; j < m-1; j++){
            area += abs(p[j+1] - p[j]);
        }
        area += p[m-1];
    }
    for (int j = 0; j < m; j++){
        area += model[0][j];
        for (int i = 0; i < n-1; i++){
            area += abs(model[i+1][j] - model[i][j]);
        }
        area += model[n-1][j];
    }
    cout << area << endl;
    return 0;
}
