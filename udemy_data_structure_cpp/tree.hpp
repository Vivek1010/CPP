#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->value = data;
        left = nullptr;
        right = nullptr;
    }
};

class BSTtree
{
private:
    Node *root;

public:
    BSTtree()
    {
        root = nullptr;
    }
    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            // cout << newNode->value << " is root now" << endl;
            return true;
        }
        Node *temp = root;
        while (temp)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    // cout << newNode->value << " is inserted  at left" << endl;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    // cout << newNode->value << " is inserted at right " << endl;
                    return true;
                }
                temp = temp->right;
            }
        }
        return false;
    }
    void printTree(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        printTree(temp->left);
        cout << temp->value << " ";
        printTree(temp->right);
    }

    void print()
    {
        // cout << "root = " << root << endl;
        Node *temp = getRoot();
        printTree(temp);
    }
    Node *getRoot()
    {
        return root;
    }

    bool serach(int data)
    {
        Node *temp = getRoot();
        while (temp)
        {
            if (data < temp->value)
            {
                temp = temp->left;
            }
            else if (data > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};