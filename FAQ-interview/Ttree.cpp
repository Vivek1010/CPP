#include "Tertree.h"

int main()
{
    TTree *t = new TTree();
    t->buildTree();
    t->printTree();
    delete t;
    return 1;
}

void TTree::buildTree()
{
    if (root == nullptr)
    {
        root = new Node(arr[idx]);
        idx++;
        q.push(root);
    }
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        for (int i = 0; i < SIZE; i++)
        {
            if (idx < arr.size())
            {
                temp->child[i] = new Node(arr[idx]);
                idx++;
                q.push(temp->child[i]);
            }
        }
    }
}
void TTree::printTree()
{
    if (root == nullptr)
    {
        cout << "NO TREE ...\n";
        return;
    }
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        for (int i = 0; i < SIZE; i++)
        {
            if (temp->child[i])
            {
                q.push(temp->child[i]);
            }
        }
        // level++;
    }
}