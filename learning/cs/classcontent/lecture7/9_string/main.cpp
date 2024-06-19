#include <iostream>
#include <string>
#include <Vector.h>
using namespace std;

// MyString
class MyString {
public:
    // Default constructor
    MyString() {}

    // Construct a string from a standard string
    MyString(const string& s) {
        for (int i = 0; i < s.length(); i++)
            str.add(s[i]);
    }

    // Get the length
    int length() const {
        return str.size();
    }

    // Get the i-th character
    char at(int i) const {
        return str[i];
    }

    // Add a character to the end of the string
    void add(char ch) {
        str.add(ch);
    }

    // Get the substring starting at i
    MyString substr(int i) const {
        MyString res;
        for (int j = i; j < str.size(); j++)
            res.add(str[j]);
        return res;
    }

    // Get the n characters starting at i
    MyString substr(int i, int n) const {
        MyString res;
        for (int j = i; j < str.size() && j-i < n; j++)
            res.add(str[j]);
        return res;
    }

    // Remove n characters starting from n
    void remove(int i, int n) {
        while (i < str.size() && n > 0) {
            str.remove(i);
            n--;
        }
    }

    // Insert a string at position i
    void insert(int i, const MyString& s) {
        for (int j = s.length()-1; j >= 0; j--)
            str.insert(i, s.at(j));
    }

private:
    Vector<char> str;
};

void printMyString(const MyString& s)
{
    // Convert back to standard string
    string res;
    for (int i = 0; i < s.length(); i++)
        res += s.at(i);
    cout << "\"" << res << "\"" << endl;
}


int main()
{
    MyString str("Hello world!");

    printMyString(str);
    printMyString(str.substr(6));
    printMyString(str.substr(6,5));
    printMyString(str.substr(6,20));

    str.remove(6,5);
    printMyString(str);

    MyString f("friend");
    str.insert(6, f);
    printMyString(str);

    return 0;
}
