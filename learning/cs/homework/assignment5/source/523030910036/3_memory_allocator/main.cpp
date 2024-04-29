# include <iostream>
# include <sstream>

using namespace std;
struct mem{
    int x;
    int y;
    int a;
    mem* next;
};

mem dummy;

mem* head = &dummy;

int s,n,m;

mem* newmem(const int& a,const int& x,const int& y, mem* next){
    mem* node = new mem;
    (*node).a = a;
    (*node).x = x;
    (*node).y = y;
    (*node).next = next;
    return node;
}

void R(const int &a){
    mem* p = dummy.next;
    mem* current = &dummy;
    while (p != nullptr){
        if (p->a == a){
            current->next = p->next;
            delete p;
            p = current->next;
        }
        else {
            current = p;
            p = current->next;
        }
    }
}

void S(){
    mem* p = dummy.next;
    mem* current = &dummy;
    while (p != nullptr){
        if (p->x > (current->x+current->y)){
            (*p).x = current->x + current->y;
        }
        current = p;
        p = current->next;
    }
}

void A1(const int& a,const int& x,const int& y){
    mem* p = dummy.next;
    mem* current = &dummy;
    if (p == nullptr){
        if (x+y > s){
            cout << "error" << endl;
            return;
        }
        p = newmem(a,x,y,nullptr);
        dummy.next = p;
        return;
    }
    while (p != nullptr && p->x < x+y){
        p = p->next;
        current = current->next;
    }
    if (current->x + current->y <= x && (x+y <= s)){
        p = newmem(a,x,y,p);
        (*current).next = p;
        return;
    }
    else{
        cout << "error" << endl;
    }
}

void f(const int& a,const int& y){
    mem* current = dummy.next;
    if (current == nullptr){
        if (y>s){
            cout << "error" << endl;
            return;
        }
        mem* p = newmem(a,0,y,nullptr);
        dummy.next = p;
        return;
    }
    if ((current->x) >= y){
        mem* p = newmem(a,0,y,current);
        dummy.next = p;
        return;
    }
    mem* p = current->next;
    while (p != nullptr && (p->x - (current->x + current->y)) < y){
        current = p;
        p = current->next;
    }
    if (p != nullptr){
        p = newmem(a,current->x+current->y,y,p);
        (*current).next = p;
        return;
    }
    if (current->x+current->y+y <= s){
        p = newmem(a,(current->x + current->y),y,p);
        (*current).next = p;
        return;
    }
    else {
        cout << "error" << endl;
    }
}

void b(const int& a,const int& y){
    mem* current = dummy.next;
    mem* q = &dummy;
    int k = 0;
    if (current == nullptr){
        mem* p = newmem(a,0,y,nullptr);
        (*q).next = p;
        return;
    }
    if (current->x >= y){
        k = current->x;
    }
    mem* p = current->next;
    while (p != nullptr){
        if (p->x - (current->x + current->y) > k){
            q = current;
            k = p->x - (current->x + current->y);
        }
        current = p;
        p = current->next;
    }
    if (s-(current->x + current->y) >= y && s-(current->x+current->y) > k){
        p = newmem(a,(current->x + current->y),y,p);
        (*current).next = p;
        return;
    }
    if (k < y){
        cout << "error" << endl;
    }else{
        mem* qnext = newmem(a,q->x+q->y,y,q->next);
        (*q).next = qnext;
    }
}

void smallest(const int& a,const int& y){
    mem* current = dummy.next;
    mem* q = &dummy;
    int k = 0;
    if (current == nullptr){
        mem* p = newmem(a,0,y,nullptr);
        (*q).next = p;
        return;
    }
    if (current->x >= y){
        k = current->x;
    }
    mem* p = current->next;
    while (p != nullptr){
        if (k == 0 && (p->x - (current->x + current->y) >= y)){
            q = current;
            k = p->x - (current->x + current->y);
        }
        if (p->x - (current->x + current->y) >= y && (p->x - (current->x + current->y)) < k){
            q = current;
            k = p->x - (current->x + current->y);
        }
        current = p;
        p = current->next;
    }
    if (s-(current->x+current->y) >= y && (k < y || s-(current->x+current->y) < k)){
        p = newmem(a,(current->x + current->y),y,p);
        (*current).next = p;
        return;
    }
    if (k < y){
        cout << "error" << endl;
    }else{
        mem* qnext = newmem(a,q->x+q->y,y,q->next);
        (*q).next = qnext;
    }
}

void A2(const int& a,const int& y,const char& c){
    if (c == 'f'){
        f(a,y);
    }
    else if (c == 'b'){
        b(a,y);
    }
    else {
        smallest(a,y);
    }
}

void O(){
     mem* p = dummy.next;
     while (p != nullptr){
        cout << p->x << " "<< p->y << " " << p->a << endl;
        p = p->next;
     }
}

void op(){
    string str;
    getline(cin, str);
    istringstream iss(str);
    string ope;
    iss >> ope;
    if (ope == "R"){
        int a;
        iss >> a;
        R(a);
    }
    else if (ope == "S"){
        S();
    }
    else if (ope == "A1"){
        int a,x,y;
        iss >> a >> x >> y;
        A1(a,x,y);
    }
    else if (ope == "A2"){
        int a,y;
        char c;
        iss >> a >> y >> c;
        A2(a,y,c);
    }
    else if (ope == "O"){
        O();
    }
}

int main()
{
    cin >> s >> n >> m;
    cin.ignore();
    dummy.next = nullptr;
    for (int i = 0; i < m; i++){
        op();
    }
    return 0;
}
