#include <iostream>
using namespace std;
/*
�����ַ����
���룺��һλ��λ��char�����ַ�1���ַ�2�������char��,��λ��char��
�������
ȫ��״̬����λ���£��������
*/
void ccadd(char ci, char c1, char c2, char& res, char& co){
    int ai, a1, a2;
    ai = ci - 'a';
    a1 = c1 - 'a';
    a2 = c2 - 'a';
    int resi;
    resi = ai + a1 + a2;
    res = 'a' + (resi % 26);
    co = 'a' + (resi / 26);
}
/*
�����ַ������
���룺�ַ���1���ַ���2�������string����
�������
ȫ��״̬���������
*/
void ssadd(string s1, string s2, string& res){
    char res0, co0;
    ccadd('a', s1[s1.length()-1], s2[s2.length()-1],res0,co0);
    res = res0 + res;
    for (int i = s1.length()-2; i >= 0; i--){
        ccadd(co0,s1[i],s2[i],res0,co0);
        res = res0 + res;
    }
    if (co0 != 'a'){
        res = co0 + res;
    }
}
/*
�����ַ����
���룺��һλ��λ��char�����ַ�1���ַ�2�������char��,��λ��char��
�������
ȫ��״̬����λ���£��������
*/
void ccmul(char ci, char c1, char c2, char& res, char& co){
    int m1, m2, carry;
    m1 = c1 - 'a';
    m2 = c2 - 'a';
    carry = ci - 'a';
    int resi;
    resi = m1 * m2 + carry;
    res = 'a' + (resi % 26);
    co = 'a' + (resi / 26);
}
/*
�ַ������ַ����
���룺�ַ������ַ��������string��
�������
ȫ��״̬���������
*/
void scmul(string s1, char c, string& res){
    char res0, co0;
    ccmul('a',s1[s1.length()-1],c,res0,co0);
    res = res0 + res;
    for (int i = s1.length()-2; i >= 0; i--){
        ccmul(co0,s1[i],c,res0,co0);
        res = res0 + res;
    }
    if (co0 != 'a'){
        res = co0 + res;
    }
}
/*
�����ַ������
���룺�ַ���1���ַ���2�������string��
�������
ȫ��״̬���������
*/
void ssmul(string s1, string s2, string& res){
    string res0;
    scmul(s1,s2[s2.length()-1],res0);
    res = res0 + res;
    for (int i = s2.length()-2; i >= 0; i--){
        res0 = "";
        scmul(s1,s2[i],res0);
        for (int k = 0; k < s2.length()-1 -i; k++ ) {
            res0 += "a";
        }
        string res1 = "";
        if (res.length() < res0.length()){
            res1 = res1.append(res0.length()-res.length(),'a');
            res1 += res;
        }else{
            res1 = res;
        }
        string res2 = "";
        ssadd(res1,res0,res2);
        res = res2;
    }
}
/*
ȥ���ַ���������λ��a
���룺�����string��
�����
ȫ��״̬��ɾ��������λ��a
*/
void reducea(string& res){
    while (res.size() >= 2){
        if (res[0] == 'a'){
            res.erase(0,1);
        }else{
            break;
        }
    }
}
/*
��ʮ�������ַ������
*/
int main() {
    string s1,s2;
    cin >> s1 >> s2;
    if (s1.length() < s2.length()){
        string s3;
        s3 = s1;
        s1 = s2;
        s2 = s3;
    }
    string res = "";
    ssmul(s1,s2,res);
    reducea(res);
    cout << res;
    return 0;
}
