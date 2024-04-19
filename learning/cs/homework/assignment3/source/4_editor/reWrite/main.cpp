#include <iostream>
#include <Vector.h>
#include <Stack.h>
//#include <Map.h>
#include <istream>

using namespace std;
typedef pair<int,int> point;

point cursor(1,0);
Vector<string> txt;
Stack<function<void>> undoOperation;
Stack<function<void>> redoOperation;
Stack<string> uOpe;
Stack<string> rOpe;
Vector<string> operation;
//Vector<string> reope;
Stack<string> reope;

string c(int m, int n){
    if (m > txt.size()){
        return;
    }
    if (n > txt[m-1].size()){
        return;
    }
    cursor.first = m;
    cursor.second = n;
}

void i(const string& s){
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
}

void d(int k){
    if (cursor.second <= k) {
        txt[cursor.first-1].clear();
        cursor.second = 0;
        return;
    }
    cursor.second -= k;
    txt[cursor.first - 1].erase(cursor.second, k);
}

void ENT(){
    txt.insert(cursor.first,txt[cursor.first-1].substr(cursor.second));
    txt[cursor.first-1].erase(cursor.second);
    cursor.first += 1;
    cursor.second = 0;
}

//void u(){
//    string undo = uOpe.pop();
//    if (undo == "r"){
//        uOpe.push(rOpe.pop());
//    }else{
//        rOpe.push(undo);
//    }
//}

void u(){
    if (operation.isEmpty()){
        return;
    }
    string undo = operation[operation.size()-1];
    if (undo == "p" ){
        return;
    }
//    if (undo == "r"){
//        operation.remove(operation.size()-1);
//        operation.add(reope[reope.size()-1]);
//        reope.remove(reope.size()-1);
//        return;
//    }
//    operation.remove(operation.size()-1);
//    if (undo[0] == 'r'){
//        operation.add(reope[reope.size()-1]);
//        reope.remove(reope.size()-1);
//    }else{
//        reope.add(undo);
//    }
    if (undo[0] == 'c'){
        istringstream iss0 (undo);
        int m, n;
        iss0 >> m >> n;
        if (m > txt.size() || n > txt[m-1].size()){
            operation.remove(operation.size()-1);
            u();
            return;
        }
    }
    operation.remove(operation.size()-1);
//    reope.add(undo);
    reope.push(undo);
}

//void r(){
//     uOpe.push(rOpe.pop());
//}

void r(){
    if (reope.isEmpty()){
        return;
    }
//    operation.add(reope[reope.size()-1]);
//    reope.remove(reope.size()-1);
    operation.add(reope.pop());
}

void p(){
    while(!operation.isEmpty()){
        istringstream iss(operation[0]);
        string name;
        iss >> name;
        if (name == "c"){
            int m,n;
            iss >> m >> n;
            c(m,n);
        }
        else if (name == "i"){
            string s = operation[0].substr(2);
            i(s);
        }
        else if (name == "d"){
            int k;
            iss >> k;
            d(k);
        }
        else if (name == "ENT"){
            ENT();
        }
        operation.remove(0);
    }
    for (int i =0 ; i < txt.size() ; i++){
        cout << txt[i] << endl;
    }
//    uOpe.clear();
    operation.clear();
}

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
            operation.add(s);
        }
    }
    return 0;
}
