#include<bits/stdc++.h>
struct Node
{
    bool isTerminal;
    unordered_map<char, Node*> childNode;

    Node()
    {
        isTerminal = false;
    }
};

void insert(Node* temp, string word)
{
    for(char c : word)
    {
        if(temp->childNode[c] != NULL)
        {
            temp->childNode[c] = new Node();
            
        }
        temp = temp->childNode[c]; 
    }
    temp->isTerminal = true;
}

void printT(Node *temp, string prefix)
{
    if (temp == NULL) return;
    if(temp->isTerminal)
    {
        cout << prefix << endl;
    }
    for(auto it : temp->childNode)
    {
        printT(it.second, prefix + it.first);
    }
}


void deleteNode()
int main()
{
    Node root = new Node();
    return 1; 
}