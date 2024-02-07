#include "bst.h"

int main()
{
    bst *b = new bst();
    for (int i = 0; i < 100; i++)
    {
       b->insert(i);
    }
    b->printBst();
    delete b;
    return 1;
}
/// @brief Insert into the BST.
/// @param val 
void bst::insert(int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return;
    }
    Node *runner = root;
    while(runner)
    {
        if (runner->left == nullptr && val < runner->data)
        {
            runner->left = new Node(val);
            return;
        }
        else if (runner->right == nullptr && val > runner->data)
        {
            runner->right = new Node(val);
            return;
        }

        if(val < runner->data)
        {
            runner = runner->left;
        }
        else 
        {
            runner = runner->right;
        }
    }
}

void bst::printBst()
{
    _printBst(root);
}
void 
bst::_printBst(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    _printBst(root->left);
    cout << root->data << " ";
    _printBst(root->right);
}
