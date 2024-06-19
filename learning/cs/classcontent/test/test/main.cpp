#include <iostream>
#include <iomanip>

using namespace std;

int& id(int& x){
    return x;
}

int printMatrix(int *mat[4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++)
            cout << setw(4) << mat[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    /*
    int a = 0;
    cout << &a << endl;
    int *p = &id(a);
    cout << p << endl;
    const int* p1 = &a;
    a = 11;
    cout << p1 << endl;
//    *p1 = 11;
//   int mat[4][1] = {{1},{2},{3},{4}};
//    printMatrix(mat);
    int d[4] = {1,2,3,4};
    int *p3 = d;
    cout << *p3++ << endl;
    cout << *p3 << endl;
    return 0;
    */
    /*
    string s;
    getline(cin,s);
    string a;
    istringstream iss(s);
    iss >> a;
    char b;
    iss >> b;
    char c;
    iss >> c;
    if (iss){
        cout << "Y";
    }else{
        cout << c;
    }*/
    if (NULL){
        cout << "?" << endl;
    }
    string s;
    getline(cin,s);
    istringstream iss(s);
    int a,b,c;
    iss >> a >> b >> c;
    if (iss){
        cout << "Have something still." << endl;
    }
    return 0;
}
