#include <iostream>

using namespace std;
/*
int scheme(string c){
    if (c.size() < 3){
        if (stoi(c) < 26){
            return 2;
        }else {
            return 1;
        }
    }
    if (stoi(c.substr(0,2)) <= 25){
        return scheme(c.substr(1)) + scheme(c.substr(2));
    }else{
        return scheme(c.substr(1));
    }
}

int main()
{
    int n;
    cin >> n;
    string ciphertext;
    cin >> ciphertext;
    int k = 0;
    k = scheme(ciphertext) % (1000000007);
    cout << k <<endl;
    return 0;
}
*/

int scheme(char *c, ){
    if (c.size() < 3){
        if (stoi(c) < 26){
            return 2;
        }else {
            return 1;
        }
    }
    if (stoi(c.substr(0,2)) <= 25){
        return scheme(c.substr(1)) + scheme(c.substr(2));
    }else{
        return scheme(c.substr(1));
    }
}

int main()
{
    int n;
    cin >> n;
    string ciphertext;
    cin >> ciphertext;
    const char *c = ciphertext.c_str();
    int k = 0;

}
