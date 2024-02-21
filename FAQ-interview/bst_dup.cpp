#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int refCount;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        refCount = 1;
        left = right = NULL;
    }
};

void printBst(Node *temp)
{
    if (temp != NULL)
    {
        printBst(temp->left);
        cout << temp->data << " ";
        printBst(temp->right);
    }
}

Node *
insert(Node *temp, int val)
{
    if (temp == NULL)
    {
        return new Node(val);
    }
    if (temp->data == val)
    {
        temp->refCount++;
        return temp;
    }
    if (val < temp->data)
    {
        temp->left = insert(temp->left, val);
    }
    else if (val > temp->data)
    {
        temp->right = insert(temp->right, val);
    }
    return temp;
}

Node *
search(Node *temp, int val)
{
    if (temp == NULL)
    {
        cout << " Not found" << endl;
        return NULL;
    }
    if (temp->data == val)
    {
        return temp;
    }
    if (val < temp->data)
    {
        return search(temp->left, val);
    }
    else
    {
        return search(temp->right, val);
    }
    return temp;
}

Node *getMini(Node *root)
{
    // Temp is not null
    Node *temp = root;
    while (temp && temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node *
deleteNode(Node *temp, int val)
{
    if (temp == NULL)
    {
        return temp;
    }
    if (val < temp->data)
    {
        temp->left = deleteNode(temp->left, val);
    }
    if (val > temp->data)
    {
        temp->right = deleteNode(temp->right, val);
    }
    else
    {
        if (temp->refCount > 1)
        {
            temp->refCount--;
            return temp;
        }
        // case 1 - leaf
        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return NULL;
        }
        // case 2 - only left
        if (temp->left != NULL && temp->right == NULL)
        {
            Node *leftTree = temp->left;
            delete temp;
            return leftTree;
        }
        // case 3 - only right
        if (temp->left == NULL && temp->right != NULL)
        {
            Node *rightTree = temp->right;
            delete temp;
            return rightTree;
        }
        // case 4 - subtree
        else if (temp->left != NULL && temp->right != NULL)
        {
            Node *min_temp = getMini(temp->right);
            temp->data = min_temp->data;
            temp->refCount = min_temp->refCount;
            min_temp->refCount = 1;
            temp->right = deleteNode(temp->right, min_temp->data);
        }
    }
    return temp;
}

/*
Node *
deleteNode(Node *temp, int val)
{
    if (temp == NULL)
    {
        return temp;
    }
    if (temp->data == val)
    {
        if (temp->refCount > 1)
        {
            temp->refCount--;
            return temp;
        }
        // case 1 - leaf
        else if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return NULL;
        }
        // case 2 - only left
        else if (temp->left != NULL && temp->right == NULL)
        {
            Node *leftTree = temp->left;
            delete temp;
            return leftTree;
        }
        // case 3 - only right
        else if (temp->left == NULL && temp->right != NULL)
        {
            Node *rightTree = temp->right;
            delete temp;
            return rightTree;
        }
        // case 4 - subtree
        else
        {
            Node *min_temp = getMini(temp->right);
            temp->data = min_temp->data;
            temp->refCount = min_temp->refCount;
            min_temp->refCount = 1;
            temp->right = deleteNode(temp->right, min_temp->data);
        }
    }
    else if (val < temp->data)
    {
        temp->left = deleteNode(temp->left, val);
    }
    else
    {
        temp->right = deleteNode(temp->right, val);
    }
    return temp;
}
*/
int main()
{
    Node *root = NULL;
    vector<int> input{};
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        input.push_back(rand() % 5);
    }

    for (int in : input)
    {
        cout << "\ninserting ... " << in << "\n";
        root = insert(root, in);
        printBst(root);
    }
    // printBst(root);
    for (int in : input)
    {
        cout << "\ndeleteing " << in << "\n";
        root = deleteNode(root, in);
        printBst(root);
    }
    cout << "\n after delete "
         << "\n";
    // printBst(root);
    return 1;
}
