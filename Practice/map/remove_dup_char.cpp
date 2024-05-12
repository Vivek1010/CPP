//
// given the bigger string input
// remove the dupplicate and print then lexographic order
//
#include <bits/stdc++.h>
using namespace std;
/*
string remove_dup(string input)
{
    map<char, int> m;
    string ans;
    for (char c : input)
    {
        if (m.find(c) == m.end())
        {
            m[c] = 1;
        }
    }
    for (auto it : m)
    {
        ans = ans + it.first;
    }
    return ans;
}
*/
string remove_dup(string input)
{
    set<char> s;
    string ans;
    for (char c : input)
    {
        s.insert(c);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        ans += *it;
    }
    return ans;
}
int main()
{
    string input = "sgdflsgfbsgghdhdsdafiywqgeflsdhfbuishfisfhggdghigizgfgwasddsff";
    cout << remove_dup(input) << "\n";
    return 1;
}