#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i < y; i++)

struct Node
{
    bool isTerminal;
    Node *child[26];

    Node()
    {
        isTerminal = false;
        FOR(i, 0, 26)
        {
            child[i] = nullptr;
        }
    }
};

class tries
{
private:
    Node *root = nullptr;

    /// @brief create a node
    /// @return
    Node *makeNode()
    {
        return new Node();
    }

    void maketerminal(Node *&temp)
    {
        temp->isTerminal = true;
    }

public:
    tries()
    {
        root = makeNode();
    }

    bool add(string word)
    {
        Node *temp = root;
        FOR(i, 0, word.size())
        {
            int data = word[i] - 'a';
            // cout << "index = " << data << " char = " << word[i] << endl;
            if (temp->child[data] == nullptr)
            {
                temp->child[data] = makeNode();
            }
            temp = temp->child[data];
        }
        temp->isTerminal = true;
        cout << setw(10) << word << " is added" << endl;
        return true;
    }

    bool search(string word)
    {
        Node *temp = root;
        FOR(i, 0, word.size())
        {
            int data = word[i] - 'a';

            if (temp->child[data] == nullptr)
            {
                cout << endl
                     << word[i] << " is not present in tries" << endl;
                return false;
            }
            temp = temp->child[data];
        }
        if (temp->isTerminal)
        {
            cout << endl
                 << word << " is present in tries" << endl;
            return true;
        }
        cout << endl
             << word << " is not present in tries" << endl;
        return false;
    }
};