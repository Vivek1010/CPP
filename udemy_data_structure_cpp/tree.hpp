#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
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
            return true;
        }
        Node *temp = root;
        while (temp)
        {
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
};