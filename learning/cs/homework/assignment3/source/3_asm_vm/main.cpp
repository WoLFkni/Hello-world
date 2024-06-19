#include <iostream>
#include <istream>
#include <Stack.h>
#include <Map.h>

using namespace std;
/*
 * 根据string类型的指令，进行对应的操作
 * 输入：所有的操作（Vector)，pc,一个表示当前可操作数据的栈，一个表示变量名和值的回应关系的映射
 * 输出：0表示成功执行，-1表示出现错误，1表示可以正常终止程序
 */
int operate(Vector<string> ops, int& pc, Stack<int>& stack, Map<string,int>& state){
    istringstream iss(ops[pc]);
    string op;
    iss >> op;
    if (op == "Add"){
        if (stack.size() < 2){
            return -1;
        }
        int a1, a2;
        a2 = stack.pop();
        a1 = stack.pop();
        stack.push(a1 + a2);
        return 0;
    }
    if (op == "Sub"){
        if (stack.size() < 2){
            return -1;
        }
        int a1, a2;
        a2 = stack.pop();
        a1 = stack.pop();
        stack.push(a1 - a2);
        return 0;
    }
    if (op == "Mul"){
        if (stack.size() < 2){
            return -1;
        }
        int a1, a2;
        a2 = stack.pop();
        a1 = stack.pop();
        stack.push(a1 * a2);
        return 0;
    }
    if (op == "Div"){
        if (stack.size() < 2){
            return -1;
        }
        int a1, a2;
        a2 = stack.pop();
        if (a2 == 0){
            return -1;
        }
        a1 = stack.pop();
        stack.push(a1 / a2);
        return 0;
    }
    if (op == "Assign"){
        string name;
        iss >> name;
        if (stack.isEmpty()){
            return -1;
        }
        state[name] = stack.pop();
        return 0;
    }
    if (op == "Var"){
        if (state.isEmpty()){
            return -1;
        }
        string name;
        iss >> name;
        stack.push(state[name]);
        return 0;
    }
    if (op == "Jmp"){
        int n;
        iss >> n;
        if (n > ops.size()){
            return -1;
        }
        pc = n;
        return operate(ops,pc,stack,state);
    }
    if (op == "JmpEq"){
        int n;
        iss >> n;
        if (stack.size() < 2){
            return -1;
        }
        if (stack.pop() == stack.pop()){
            if (n >= ops.size()){
                return -1;
            }
            pc = n;
            return operate(ops, pc, stack, state);
        }
    }
    if (op == "JmpGt"){
        int n;
        iss >> n;
        if (stack.size() < 2){
            return -1;
        }
        if (stack.pop() < stack.pop()){
            if (n >= ops.size()){
                return -1;
            }
            pc = n;
            return operate(ops, pc, stack, state);
        }
    }
    if (op == "JmpLt"){
        int n;
        iss >> n;
        if (stack.size() < 2){
            return -1;
        }
        if (stack.pop() > stack.pop()){
            if (n >= ops.size()){
                return -1;
            }
            pc = n;
            return operate(ops, pc, stack, state);
        }
    }
    if (op == "Const"){
        int n;
        iss >> n;
        stack.push(n);
        return 0;
    }
    if (op == "Print"){
        string name;
        iss >> name;
        if (!state.containsKey(name)){
            return -1;
        }
        cout << state[name] << endl;
        return 0;
    }
    if (op == "Halt"){
        return 1;
    }
    return 0;
}
/*
 * 输⼊⼀段程序，对这段程序进⾏解析，并模拟运⾏，最终输出结果。
 */
int main(){
    Stack<int> stack;
    Map<string,int> state;
    Vector<string> ops;
    int k;
    cin >> k;
    string tmp;
    getline(cin , tmp);
    for (int i = 0; i < k; i++){
        string s;
        getline(cin , s);
        ops.add(s);
    }
    int pc = 0;
    while (pc < k){
        int wholeState;
        wholeState = operate(ops,pc,stack,state);
        if (wholeState == -1){
            cout << "Error" << endl;
            break;
        }else if (wholeState == 1){
            break;
        }
        pc ++;
    }
    if (pc >= k){
        cout << "Error" << endl;
    }
    return 0;
}