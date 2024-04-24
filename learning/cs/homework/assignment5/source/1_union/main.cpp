# include <iostream>
# include <iomanip>
# include <stack.h>
# include <map.h>

using namespace std;

const int N=100;
enum Operation {AddL, AddR, SubL, SubR, Assign, Var, Jmp, JmpEq, JmpGt, JmpLt, Const, Print, Halt};
struct Command{
    Operation type;
    union {
        int i;
        double d;
        char ch;
    } value;
}cmd[N];
Stack<double> stack;
Map<char, double> state;
int pc = 0;

Command store(){
    string s;
    getline(cin,s);
    istringstream iss (s);
    string optype;
    iss >> optype;
    Command cmdi;
    if (optype == "AddL"){
        cmdi.type = AddL;
    }else if(optype == "AddR"){
        cmdi.type = AddR;
        iss >> cmdi.value.d;
    }else if(optype == "SubL"){
        cmdi.type = SubL;
    }else if(optype == "SubR"){
        cmdi.type = SubR;
        iss >> cmdi.value.d;
    }else if(optype == "Assign"){
        cmdi.type = Assign;
        iss >> cmdi.value.ch;
    }else if(optype == "Var"){
        cmdi.type = Var;
        iss >> cmdi.value.ch;
    }else if (optype == "Jmp"){
        cmdi.type = Jmp;
        iss >> cmdi.value.i;
    }else if (optype == "JmpEq"){
        cmdi.type = JmpEq;
        iss >> cmdi.value.i;
    }else if (optype == "JmpGt"){
        cmdi.type = JmpGt;
        iss >> cmdi.value.i;
    }else if(optype == "JmpLt"){
        cmdi.type = JmpLt;
        iss >> cmdi.value.i;
    }else if (optype == "Const"){
        cmdi.type = Const;
        iss >> cmdi.value.d;
    }else if (optype == "Print"){
        cmdi.type = Print;
        iss >> cmdi.value.ch;
    }else{
        cmdi.type = Halt;
    }
    return cmdi;
}

int op(const Command& cm){
    switch (cm.type){
    case AddL:{
        if (stack.size() < 2){
            return -1;
        }
        double a2 = stack.pop();
        double a1 = stack.pop();
        stack.push(a1 + a2);
        pc += 1;
        break;}
    case AddR:{
        if (stack.size() < 1){
            return -1;
        }
        double a = stack.pop();
        stack.push(a + cm.value.d);
        pc += 1;
        break;}
    case SubL:{
        if (stack.size() < 2){
            return -1;
        }
        double a2 = stack.pop();
        double a1 = stack.pop();
        stack.push(a1 - a2);
        pc += 1;
        break;}
    case SubR:{
        if (stack.size() < 1){
            return -1;
        }
        double a = stack.pop();
        stack.push(a - cm.value.d);
        pc += 1;
        break;}
    case Assign:
        if (stack.size() < 1){
            return -1;
        }
        state[cm.value.ch] = stack.pop();
        pc += 1;
        break;
    case Var:
        stack.push(state[cm.value.ch]);
        pc += 1;
        break;
    case Jmp:
        pc = cm.value.i;
        break;
    case JmpEq:{
        if (stack.size() < 2){
            return -1;
        }
        double a1 = stack.pop();
        double a2 = stack.pop();
        if (a1 == a2){
            pc = cm.value.i;
        }else{
            pc += 1;
        }
        break;}
    case JmpGt:{
        if (stack.size() < 2){
            return -1;
        }
        double a1 = stack.pop();
        double a2 = stack.pop();
        if (a1 < a2){
            pc = cm.value.i;
        }else{
            pc += 1;
        }
        break;}
    case JmpLt:{
        if (stack.size() < 2){
            return -1;
        }
        double a1 = stack.pop();
        double a2 = stack.pop();
        if (a1 > a2){
            pc = cm.value.i;
        }else{
            pc += 1;
        }
        break;}
    case Const:
        stack.push(cm.value.d);
        pc += 1;
        break;
    case Print:
        cout << fixed << setprecision(2) << state[cm.value.ch] << endl;
        pc += 1;
        break;
    case Halt:
        return 1;
    }
    return 0;
}

int main()
{
    // Todo: First read all the commands into cmd[N];
    // Then use pc as a subscript in cmd.
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        cmd[i] = store();
    }
    while (pc < n){
        int success = op(cmd[pc]);
        if (success == 1){
            break;
        }
        if (success == -1){
            cout << "Error" << endl;
        }
    }
    return 0;
}
