#include <iostream>
#include <istream>
#include <sstream>

using namespace std;

typedef uint8_t Register[2];
Register r1, r2, r3;// 声明3个寄存器
uint8_t M[512]; // 声明内存M
bool flag = true; // 表示地址是否合法

// 设置大值
void setH(Register& r, uint8_t n) {
    r[0] = n;
}
// 设置小值
void setL(Register& r, uint8_t n) {
    r[1] = n;
}
// 使⽤⼤端法存储n
void setR(Register& r, uint16_t n) {
    setH(r, n / 256);
    setL(r, n % 256);
}
// 读取大值
uint8_t readH(const Register& r) { return r[0]; }
// 读取小值
uint8_t readL(const Register& r) { return r[1]; }
//用大端法读取n
uint16_t readR(const Register& r) {
    return uint16_t(r[0]) * 256 + r[1];
}
// 读取寄存器里的值
int regread(string s){
    if (s.size() == 3){
        if (s[2] == '1'){
            return readR(r1);
        }
        else if (s[2] == '2'){
            return readR(r2);
        }
        else {
            return readR(r3);
        }
    }
    else {
        if (s[2] == '1'){
            if (s[3] == '1'){
                return readH(r1);
            }
            return readL(r2);
        }
        else if (s[2] == '2'){
            if (s[3] == '1'){
                return readH(r2);
            }
            return readL(r2);
        }
        else{
            if (s[3] == '1'){
                return readH(r3);
            }
            return readL(r3);
        }
    }
}
//设置寄存器里的一位
void regset1(string s, uint8_t num){
    if (s[2] == '1'){
        if (s[3] == '1'){
            setH(r1,num);
        }
        setL(r1,num);
    }
    else if (s[2] == '2'){
        if (s[3] == '1'){
            setH(r2,num);
        }
        setL(r2,num);
    }
    else{
        if (s[3] == '3'){
            setH(r3,num);
        }
        setL(r3,num);
    }
}
// 设置寄存器里的两位
void regset2(string s, uint16_t num){
    if (s[2] == '1'){
        setR(r1,num);
    }
    else if (s[2] == '2'){
        setR(r2,num);
    }
    else {
        setR(r3,num);
    }
}
// 读取内存中的位置
int mem(string s){
    if (s[0] == '('){
        return regread(s.substr(1,s.size()-2));
    }
    int num;
    size_t pos = s.find('%');
    if (pos != string::npos){
        num = stoul(s.substr(0,pos));
        num += regread(s.substr(pos,s.find(')')-pos));
        return num;
    }
    else {
        return stoul(s);
    }
}
// 处理1个字节的非立即数
int indirect1(const string& s){
    if (s[0] == '%'){
        return regread(s);
    }
    else{
        int address = mem(s);
        if (address > 511){
            flag = false;
            return -1;
        }
        return M[mem(s)];
    }
}
// 处理1个字节的操作数
void deal1(const string& S, int& numS){
    if (S[0] == '$'){
        numS = stoul(S.substr(1));
    }
    else {
        numS = indirect1(S);
    }
}
// 处理2个字节的非立即数
int indirect2(const string& D){
    if (D[0] == '%'){
        return regread(D);
    }
    else{
        int address = mem(D);
        if (address > 510){
            flag = false;
            return -1;
        }
        return M[address]*256 + M[address+1];
    }
}
// 处理2个字节的非立即数
void deal2(const string& D, int& numD){
    if (D[0] == '$'){
        numD = stoul(D.substr(1));
    }
    else{
        numD = indirect2(D);
    }
}
// 执行1个字节的mov
void mov1(string S,string D){
    int numS;
    deal1(S,numS);
    if (!flag){
        return;
    }
    if (D[0] == '%'){
        regset1(D,numS);
    }else{
        int address = mem(D);
        if (address > 511){
            flag = false;
            return;
        }
        M[address] = numS;
    }
}
// 执行1个字节的add
void add1(string S, string D){
    int numS;
    deal1(S,numS);
    if (!flag){
        return;
    }
    int numD;
    deal1(D,numD);
    if (!flag){
        return;
    }
    if (D[0] == '%'){
        regset1(D,numS+numD);
    }else{
        int address = mem(D);
        if (address > 511){
            flag = false;
            return;
        }
        M[address] = numS+numD;
    }
}
//执行2个字节的mov
void mov2(string S,string D){
    int numS;
    deal2(S,numS);
    if (!flag){
        return;
    }
    if (D[0] == '%'){
        regset2(D,numS);
    }else{
        int address = mem(D);
        if (address > 510){
            flag = false;
            return;
        }
        M[address] = numS / 256;
        M[address+1] = numS % 256;
    }
}
//执行2个字节的add
void add2(string S, string D){
    int numS;
    deal2(S,numS);
    if (!flag){
        return;
    }
    int numD;
    deal2(D,numD);
    if (!flag){
        return;
    }
    if (D[0] == '%'){
        regset2(D,numS+numD);
    }else{
        int address = mem(D);
        if (address > 510) {
            flag = false;
            return;
        }
        M[address] = (numS+numD) / 256;
        M[address+1] = (numS+numD) % 256;
    }
}
// 执行对应的操作
void run(string s){
    istringstream iss(s);
    string op, S, D;
    iss >> op >> S >> D;
    if (op == "mov1"){
        mov1(S,D);
    }
    else if (op == "add1"){
        add1(S,D);
    }
    else if (op == "mov2"){
        mov2(S,D);
    }
    else{
        add2(S,D);
    }
}

//通过读取指令，对寄存器和内存进⾏相应的操作，来完成计算任务
int main () {
    int x,y,z;
    cin >> x >> y >> z;
    setR(r1,x);
    setR(r2,y);
    setR(r3,z);
    for (size_t i = 0; i < 512; i++) { // 读取输入的内存数据并初始化内存M
        uint16_t tmp;
        cin >> tmp;
        M[i] = tmp;
    }
    int k;
    cin >> k;
    cin.ignore();
    for (int i = 0; i < k; i++){
        string s;
        getline(cin,s);
        run(s);
        if (!flag){
            break;
        }
    }
    if (!flag){
        cout << "segmentation fault" << endl;
        return 0;
    }
    cout << readR(r1) << " " << readR(r2) << " " << readR(r3) << endl;
    for (int i = 0; i < 512; i++){
        cout << unsigned(M[i]) << " ";
    }
    return 0;
}
