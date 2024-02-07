#include "bst.h"

int main()
{
    bst *b = new bst();
    b->insert(50);
    b->insert(0);
    b->insert(20);
    b->insert(540);
    b->insert(51);
    b->insert(2);
    b->insert(-3);
    b->insert(6);
    b->insert(456);
    b->insert(23);
    b->insert(78);
    b->insert(1);
    b->insert(9);
    b->printBst();
    b->search(78);
    b->search(789);
    cout << "Before Delete" << endl;
    b->printBst();
    b->deleteN(23);
    cout << endl
         << "After Delete" << endl;
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
    while (runner)
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

        if (val < runner->data)
        {
            runner = runner->left;
        }
        else
        {
            runner = runner->right;
        }
    }
    //_insert_rec(root, val);
}

void bst::printBst()
{
    _printBst(root);
}
void bst::_printBst(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    _printBst(root->left);
    cout << root->data << " ";
    _printBst(root->right);
}

void bst::_insert_rec(Node *&root, int val)
{
    if (root == nullptr)
    {
        root = new Node(val);
        return;
    }
    else if ((val < root->data) && (root->left == nullptr))
    {
        root->left = new Node(val);
    }
    else if ((val > root->data) && (root->right == nullptr))
    {
        root->right = new Node(val);
    }
    else
    {
        if ((val < root->data))
        {
            _insert_rec(root->left, val);
        }
        else
        {
            _insert_rec(root->right, val);
        }
    }
}

void bst::search(int val)
{
    _search_rec(root, val);
}

void bst::_search_rec(Node *root, int val)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data == val)
    {
        cout << endl
             << val << " Found in Container " << endl;
    }
    else if (val < root->data && root->left)
    {
        _search_rec(root->left, val);
    }
    else if (val > root->data && root->right)
    {
        _search_rec(root->right, val);
    }
    else
    {
        cout << val << " Not found" << endl;
    }
}
void bst::deleteN(int val)
{
    _deleteN_rec(root, val);
}
/// @brief
// There are 3 cases needs to be handled
// 1. When Node is leaf node
//    >> Just delete the node and return NULL
// 2. When Node is having only one child(left/right)
//    >> delete the Node and return the left or right child
// 3. When Node is having both the child
//    >> get the minimum value from the right side of the tree
//       and replace with the node.
//    OR >> get the maximum value of left sub-tree of the node
//          and replace with the node.
/// @param root
/// @param val
Node *bst::_deleteN_rec(Node *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == val)
    {
        // case -I  when node is leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // case -II - when Once of the child is avilable
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *left_child = root->left;
            delete root;
            return left_child;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            Node *right_child = root->right;
            delete root;
            return right_child;
        }

        // case -III

        if (root->left && root->right)
        {
            int mini = getMini(root->right);
            root->data = mini;
            root->right = _deleteN_rec(root->right, mini);
            return root;
        }
    }
    else if (val < root->data)
    {
        root->left = _deleteN_rec(root->left, val);
        return root;
    }
    else
    {
        root->right = _deleteN_rec(root->right, val);
        return root;
    }
    return root;
}

int bst::getMini(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}