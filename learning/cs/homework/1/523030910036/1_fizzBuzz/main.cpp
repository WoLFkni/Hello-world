#include <iostream>

using namespace std;
/*
该程序实现从1到n打印数字。对于3的倍数，打印“Fizz”而不是数字，对于5的倍数，打印“Buzz”。对于既是3的倍数
又是5的倍数的数字，打印“FizzBuzz”。
输入为单个整数，输出为“Fizz”、“Buzz”、“FizzBuzz”和单个整数，中间有空格。
*/
int main()
{
    int number;
    cin >> number;
    for (int i = 1; i <= number; i++){
        if (i%3 == 0){
            if (i%5 == 0){
                cout << "FizzBuzz ";
            }else{
                cout << "Fizz ";
            }
        }else{
            if (i%5 == 0){
                cout << "Buzz ";
            }else{
                cout << i << " ";
            }
        }
    }
    return 0;
}
