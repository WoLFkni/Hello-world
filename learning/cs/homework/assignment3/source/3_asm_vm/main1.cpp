#include <iostream>
#include <istream>
#include <Stack.h>
#include <Map.h>

using namespace std;

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