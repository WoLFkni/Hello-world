#include <iostream>
#include <string>
using namespace std;

int main()
{
    string* s = new string;
    *s = "hello";

    for(int i = 0; i < (*s).length(); i++)
        cout << (*s)[i] << endl;

    delete s;

    return 0;
}

