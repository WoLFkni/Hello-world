#include <iostream>

using namespace std;
bool flag = true;

// match : 检查text中是否存在子串匹配regexp描述的格式
bool match(char *regexp, char *text);

// matchstart : 检查text的开头子串是否匹配regexp
bool matchstart(char *regexp, char *text);

// matchstar : 检查text的开头子串是否匹配表达式 c*regexp
bool matchstar(char c, char *regexp, char *text);

//接收⼀个正则表达式和⼀个字符串，返回该字符串是否匹配该正则表达式。
int main(){
    char regexp[1000]; // 声明c-style string
    cin >> regexp;
    int k;
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++){
        char text[1000]; // 声明c-style string
        cin >> text;
        flag = true;
        if (match(regexp,text)){
            cout << "matched" << endl;
        }else{
            cout << "unmatched" << endl;
        }
    }
    return 0;
}

// match : 检查text中是否存在子串匹配regexp描述的格式
bool match(char *regexp, char *text){
    if (*regexp == '^'){
        regexp++;
        return matchstart(regexp,text);
    }
    while (*text != 0){
        if (matchstart(regexp,text)){
            return true;
        }
        if (!flag){
            return false;
        }
        text++;
    }
    return false;
}

// matchstart : 检查text的开头子串是否匹配regexp
bool matchstart(char *regexp, char *text){
    while (*regexp != 0){
        if (*text == 0){
            if (*regexp == '$') {
                return true;
            }
            return false;
        }
        if (regexp[1] == '*') {
            char c = *regexp;
            regexp += 2;
            return matchstar(c, regexp, text);
        }
        if (*regexp == '.'){
            text++;
            regexp++;
            return matchstart(regexp++,text);
        }
        if (*regexp == '$'){
            return false;
        }
        if (*regexp != *text){
            return false;
        }
        regexp++;
        text++;
    }
    return true;
}

// matchstar : 检查text的开头子串是否匹配表达式 c*regexp
bool matchstar(char c, char *regexp, char *text){
    if (c == '.'){
        if (*regexp == 0){
            return true;
        }
        if (*text == 0){
            if (*regexp == '$'){
                return true;
            }
            flag = false;
            return flag;
        }
        return match(regexp,text);
    }
    while (*text == c){
        text++;
    }
    return matchstart(regexp,text);
}
