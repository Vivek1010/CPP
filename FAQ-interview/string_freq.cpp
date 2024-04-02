/*
#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s = "aabbccccaadd";
    //
    // desired output
    // d -> 2, c ->4, b->2, a->2
    map<char, int> m;
    for (char c : s)
    {
        m[c]++;
    }

    for (auto it = m.crbegin(); it != m.crend(); it++)
    {
        cout << it->first << it->second << endl;
    }

    return 1;
}
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

// #include"words.h"

using namespace std;

typedef std::pair<int, std::string> Node;

bool cmp(Node *a, Node *b)
{
    if (a->first == b->first)
    {
        return b->second < a->second;
    }
    return b->first < a->first;
}

typedef set<Node *, decltype(&cmp)> TST;
typedef unordered_map<string, Node *> SToN_MAP;

void print_list(TST &ms)
{
    for (auto x : ms)
    {
        cout << "(" << x->first << ", " << x->second << ")";
    }
    cout << "\n";
}

int main()
{
    vector<string> a = {"Def", "Ghi", "Def", "123", "456", "Abc", "Abc", "Ghi", "Abc", "987"};

    SToN_MAP freq_map;
    TST ms(&cmp);

    for (int i = 0; i < a.size(); ++i)
    {
        const auto s = a[i];
        auto p = freq_map.find(s);
        //cout << "\n after elem: " << s << " [idx: " << i << "] => ";
        if (p == freq_map.end())
        {
            Node *pr = new Node(1, s);
            freq_map[s] = pr;
            ms.insert(pr);
        }
        else
        {
            ms.erase(p->second);
            p->second->first++;
            ms.insert(p->second);
        }
        print_list(ms);
    }
    cout << "\n\n";

    return 0;
}