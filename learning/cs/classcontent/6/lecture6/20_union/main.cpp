#include <iostream>
#include <string>
using namespace std;

// A token may be one of the following values
// A character, an integer or a double
union Token {
    char c;
    int  i;
    double d;
};


int main()
{
    Token tok;
    tok.c = 'a';
    cout << tok.c << endl;

    tok.i = 65;
    cout << tok.i << endl;
    cout << tok.c << endl;

    return 0;
}
