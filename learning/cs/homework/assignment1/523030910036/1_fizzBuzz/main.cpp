#include <iostream>

using namespace std;
/*
�ó���ʵ�ִ�1��n��ӡ���֡�����3�ı�������ӡ��Fizz�����������֣�����5�ı�������ӡ��Buzz�������ڼ���3�ı���
����5�ı��������֣���ӡ��FizzBuzz����
����Ϊ�������������Ϊ��Fizz������Buzz������FizzBuzz���͵����������м��пո�
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
