#include <iostream>
#include <string>
#include <sstream>
#include <vector.h>
using namespace std;

enum InstrType {ASSIGN, VAR, CONST, PRINT, JUMP, ADD};

union InstrValue {
    char name;
    int pc;
    int v;
};

struct Instr {
    InstrType type;
    InstrValue value;
};

Instr decodeInstr(const string& s)
{
    istringstream iss(s);
    string instrName;
    iss >> instrName;

    Instr instr;

    if (instrName == "Assign") {
        char c;
        iss >> c;
        instr.type = ASSIGN;
        instr.value.name = c;
    } else if (instrName == "Var") {
        char c;
        iss >> c;
        instr.type = VAR;
        instr.value.name = c;
    } else if (instrName == "Const") {
        int v;
        iss >> v;
        instr.type = CONST;
        instr.value.v = v;
    } else if (instrName == "Print") {
        char c;
        iss >> c;
        instr.type = PRINT;
        instr.value.name = c;
    } else if (instrName == "Jump") {
        int i;
        iss >> i;
        instr.type = JUMP;
        instr.value.pc = i;
    } else if (instrName == "Add") {
        instr.type = ADD;
    }

    return instr;
}

void printInstr(const Instr& i)
{
    switch (i.type) {
    case ASSIGN:
        cout << "Assign " << i.value.name << endl;
        break;

    case VAR:
        cout << "Var " << i.value.name << endl;
        break;

    case CONST:
        cout << "Const " << i.value.v << endl;
        break;

    case PRINT:
        cout << "Print " << i.value.name << endl;
        break;

    case JUMP:
        cout << "Jump " << i.value.pc << endl;
        break;

    case ADD:
        cout << "Add" << endl;
        break;
    }
}

int main()
{
    int n;
    cin >> n;
    string line;
    getline(cin, line);

    Vector<Instr> vec;

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        vec.add(decodeInstr(line));
    }

    cout << "----------------" << endl;

    for (int i = 0; i < n; i++)
        printInstr(vec[i]);

    return 0;
}
