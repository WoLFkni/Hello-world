#include <iostream>

using namespace std;
/*
检查是否回文句
输入：原句子（string）
输出：1（是回文句）/0（不是回文句）
全局状态：不改变
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
检查是否回文词
输入：原句子（string），单词开始的位置（int），单词结束的位置（int）
输出：1（是回文词）/0（不是回文词）
全局状态：不改变
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
以一个字符串作为输入，如果整个字符串是一个回文句，则输出"No!"
如果该字符串自身不是回文句，但其中包含回文词，则将回文词删除。
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
