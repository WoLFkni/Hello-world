#include <iostream>

using namespace std;
/*
�ó���ʵ�֣��ж�һ�����Ƿ�ֻ����������2��3��5
���룺һ��������
�����"Yes"��"No"
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
