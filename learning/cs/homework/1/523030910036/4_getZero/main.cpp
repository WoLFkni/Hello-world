#include <iostream>

using namespace std;
/*
该程序实现：给定两个非负整数，不断用大的减去小的，使得其中至少一个为0得到所经的操作数的操作数。
输入：两个非负整数
输出：一个整数代表所经操作数
*/
int main()
{
    int num1, num2, cnt = 0;
    cin >> num1 >> num2;
    while (num1 !=0 && num2 !=0){
        if (num1 >= num2 ){
            num1 -= num2;
        }else{
            num2 -= num1;
        }
        cnt += 1;
    }
    cout << cnt;
    return 0;
}
