#include <iostream>
#include <stack>
#include <string>
using namespace std;

string
reverser(const string &inputStr)
{
    stack<char> s;
    string returnStr{};
    for (char c : inputStr)
        s.push(c);

    for (char c : inputStr)
    {
        returnStr.push_back(s.top());
        s.pop();
    }
    return returnStr;
}
int main()
{
    string inputStr[] = {"abcdefg", "hijklmn", "opqrstuvwxyz"};
    for (string inStr : inputStr)
        cout << reverser(inStr) << endl;
    return 1;
}