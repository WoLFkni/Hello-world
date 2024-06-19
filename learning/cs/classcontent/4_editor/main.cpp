#include <iostream>
#include <Vector.h>
#include <Stack.h>
#include <istream>

using namespace std;
typedef pair<int,int> point;

point cursor(1,0);
Vector<string> txt;
Stack<string> uOpe;
Stack<string> rOpe;
/*
 *进行相应操作
 */
string operate(string s);
/*
 * 改变光标位置
 * 输入光标位置参数，将光标移动到第 n ⾏第 m 个字符后
 * 返回它的逆操作（string类型）
 */
string c(int m, int n){
    if (m > txt.size()){
        return "pass";
    }
    if (n > txt[m-1].size()){
        return "pass";
    }
    int m0 = cursor.first;
    int n0 = cursor.second;
    cursor.first = m;
    cursor.second = n;
    string res = "c ";
    res += to_string(m0);
    res += " ";
    res += to_string(n0);
    return res;
}
/*
 * 插入字符串
 * 输入要插入的字符串，在当前光标后插⼊字符串 s ，插⼊结束后光标移动到 s 末尾
 * 输出它的逆操作（string类型）
 */
string i(const string& s){
    string res = "d ";
    if (txt.isEmpty()){
        txt.add(s);
        cursor.first = 1;
        cursor.second = s.size();
    }
    else if(txt[cursor.first-1].size() == cursor.second){
        txt[cursor.first-1].append(s);
        cursor.second += s.size();
    }
    else {
        txt[cursor.first - 1].insert(cursor.second, s);
        cursor.second += s.size();
    }
    res += to_string(s.size());
    return res;
}
/*
 * 删一段字符串
 * 输入需要删除的字符串长度，从当前光标开始，从后往前删除 min(k,m) 个字符（ m 表示当前光标位置到当前⾏⾏⾸的字符数⽬），删除结束后光标移动到被删除字符串的开始位置
 * 输出它的逆操作（string类型）
 */
string d(int k){
    string res = "i ";
    string s;
    if (cursor.second <= k) {
        s = txt[cursor.first-1];
        txt[cursor.first-1].clear();
        cursor.second = 0;
        res += s;
        return res;
    }
    cursor.second -= k;
    s = txt[cursor.first - 1].substr(cursor.second,k);
    txt[cursor.first - 1].erase(cursor.second, k);
    res += s;
    return res;
}
/*
 * 换行
 * 无输入
 * 输出逆操作（string类型）
 */
string ENT(){
//    string res = "ent ";
    txt.insert(cursor.first,txt[cursor.first-1].substr(cursor.second));
    txt[cursor.first-1].erase(cursor.second);
    cursor.first += 1;
    cursor.second = 0;
    return "ent";
}
/*
 * 换行的逆操作
 * 无输入，作用：取消换行
 * 输出换行的操作（string类型）
 */
string ent(){
    cursor.second = txt[cursor.first-2].size();
    txt[cursor.first-2].append(txt[cursor.first-1]);
    txt.remove(cursor.first-1);
    cursor.first -= 1;
    return "ENT";
}
/*
 * 撤销
 * 无输入输出
 * 如果有可撤回操作，则撤回操作
 */
void u(){
    if (uOpe.isEmpty()){
        return;
    }
    rOpe.push(operate(uOpe.pop()));
}
/*
 * 重做
 * 无输入输出
 * 如果有则重做上一个被撤销的操作
 */
void r(){
    if (rOpe.isEmpty()){
        return;
    }
    uOpe.push(operate(rOpe.pop()));
}
/*
 * 打印
 * 无输入，输出当前全部文本
 */
void p(){
    for (int i = 0; i < txt.size(); i++){
        cout << txt[i] << endl;
    }
}
/*
 * 根据所给定的string类型操作指令执行相应函数
 * 输入：指令（string）
 * 返回：指令对应的逆操作（string)
 */
string operate(string s){
    istringstream iss(s);
    string name;
    iss >> name;
    if (name == "c"){
        int m,n;
        iss >> m >> n;
        return c(m,n);
    }
    else if (name == "i"){
        s = s.substr(2);
//        iss >> s;
        return i(s);
    }
    else if (name == "d"){
        int k;
        iss >> k;
        return d(k);
    }
    else if (name == "ENT"){
        return ENT();
    }
    else if (name == "ent"){
        return ent();
    }
}
/*
 * 实现⼀个通过命令⾏来进⾏操作的⽂本编辑器，它具有最简单的编辑功能（如插⼊，删除，撤回等）
 */
int main(){
    int k;
    string tmp;
    cin >> k;
    getline(cin, tmp);
    for (int i = 0; i < k; i++){
        string s;
        getline(cin , s);
        istringstream iss (s);
        string s0;
        iss >> s0;
        if (s0 == "u"){
            u();
        }
        else if (s0 == "r"){
            r();
        }
        else if (s0 == "p"){
            p();
        }
        else{
            uOpe.push(operate(s));
            if (uOpe.peek() == "pass"){
                uOpe.pop();
            }
        }
    }
    return 0;
}
