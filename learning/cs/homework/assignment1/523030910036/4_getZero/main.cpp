#include <iostream>

using namespace std;
/*
�ó���ʵ�֣����������Ǹ������������ô�ļ�ȥС�ģ�ʹ����������һ��Ϊ0�õ������Ĳ������Ĳ�������
���룺�����Ǹ�����
�����һ��������������������
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
