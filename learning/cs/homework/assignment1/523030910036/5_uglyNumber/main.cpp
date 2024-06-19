#include <iostream>

using namespace std;
/*
该程序实现：判断一个数是否只包含质因数2，3，5
输入：一个正整数
输出："Yes"或"No"
*/
int main()
{
    int number;
    cin >> number;
    while (number%2 == 0){
        number /= 2;
    }
    while (number%3 == 0){
        number /= 3;
    }
    while (number%5 == 0){
        number /= 5;
    }
    if (number == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
