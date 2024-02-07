#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    ~Node()
    {
        // TODO
        //delete this->left;
        //delete this->right;
    }
};

class bst
{
public:
    Node *root;
    bst()
    {
        root = nullptr;
    }
    ~bst()
    {
        delete root;
    }
    void insert(int val);
    void printBst();
    void search(int val);
    void deleteN(int val);
    int getMini(Node* root);

private:
    void _printBst(Node *root);
    void _insert_rec(Node* &root, int val);
    void _search_rec(Node *root,  int val);
    Node* _deleteN_rec(Node *root, int val);
};