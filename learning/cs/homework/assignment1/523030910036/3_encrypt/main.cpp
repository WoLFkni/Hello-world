#include <iostream>
#include <math.h>

using namespace std;
/*
�ó���ʵ�֣�����12λѧ�ţ�������ܺ���������ܷ����ǽ�����ÿһλ�����ּ�3������10��0
��ʼ������1�õ�4��9�õ�2��
����12λ����ѧ��
���12λ����ѧ��
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
