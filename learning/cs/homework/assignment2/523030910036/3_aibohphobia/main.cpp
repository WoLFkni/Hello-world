#include <iostream>

using namespace std;
/*
����Ƿ���ľ�
���룺ԭ���ӣ�string��
�����1���ǻ��ľ䣩/0�����ǻ��ľ䣩
ȫ��״̬�����ı�
*/
bool checksentence(string str){
    int p=0, q=str.length()-1;
    while (p <= q){
        if (str[p] == ' '){
            p += 1;
        }
        if (str[q] == ' '){
            q -= 1;
        }
        if (tolower(str[p]) != tolower(str[q])){
            return false;
        }
        p++;
        q--;
    }
    return true;
}
/*
����Ƿ���Ĵ�
���룺ԭ���ӣ�string�������ʿ�ʼ��λ�ã�int�������ʽ�����λ�ã�int��
�����1���ǻ��Ĵʣ�/0�����ǻ��Ĵʣ�
ȫ��״̬�����ı�
*/
bool checkword(string& str,int p, size_t n){
    while (p <= n){
        if (tolower(str[p]) != tolower(str[n])){
            return false;
        }
        p++;
        n--;
    }
    return true;
}
/*
��һ���ַ�����Ϊ���룬��������ַ�����һ�����ľ䣬�����"No!"
������ַ��������ǻ��ľ䣬�����а������Ĵʣ��򽫻��Ĵ�ɾ����
*/
int main()
{
    string str;
    getline(cin, str);
    if (checksentence(str)){
        cout << "No!";
    }else{
        size_t n = str.find(' ');
        int p = 0;
        while (n != string::npos){
            if (n-p == 1){
                str.erase(p,2);
            }
            else if (checkword(str,p,n-1)){
                str.erase(p,n-p+1);
            }
            else{
                p = n+1;
            }
            n = str.find(' ',p);
        }
        if(checkword(str,p,str.length()-1)){
            str.erase(p,str.length()-p);
        }
        cout << str << endl;
    }
    return 0;
}
