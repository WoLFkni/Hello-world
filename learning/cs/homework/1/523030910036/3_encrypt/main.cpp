#include <iostream>
#include <math.h>

using namespace std;
/*
该程序实现：输入12位学号，将其加密后输出。加密方法是将该数每一位的数字加3，超过10从0
开始。比如1得到4，9得到2。
输入12位整数学号
输出12位整数学号
*/
int main()
{
    long long m;//message
    cin >> m;
    long long s = 0;
    for (int i=0; i<=11; i++){
        s += ((m % 10 + 3) % 10) * pow(10,i);
        m /= 10;
    }
    cout << s;
    return 0;
}
