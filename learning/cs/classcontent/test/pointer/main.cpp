#include <iostream>
#include <assert.h>
using namespace std;

/*
struct a{
    int v;
    a* next;
};

int main()
{
    a *p1 = new a;
    a *p2 = new a;
    (*p2).v = 0;
    p1->next = p2;
    cout << p1->next->v << endl;
    delete p1;
    delete p2;
    return 0;
}
*/
/*
class rational{
public:
    rational(): p(0),q(1){
    }

    rational(int m,int n): p(m),q(n){
        assert (n!=0);
    }

    int getp() const{
        return p;
    }
    int getq() const{
        return q;
    }
private:
    int p,q;
};

int main()
{
    rational r;
    cout << r.getp() << r.getq() << endl;
    rational r1(9,0);
    return 0;
}
*/
int main(){
    string s = "123456";
    string c;
    c = s.substr(0,2);
    cout << stoi(c);
    cout << stoi(s.substr(0,2));
    return 0;
}
