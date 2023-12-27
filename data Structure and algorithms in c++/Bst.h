#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
private:
    TreeNode *insert(TreeNode *node, int data)
    {
        if (node == nullptr)
        {
            return (new TreeNode(data));
        }
        if (data < node->val)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void printBst(TreeNode *root)
    {
        if (!root)
            return;
        printBst(root->left);
        cout << root->val << " ";
        printBst(root->right);
    }

    void printLevel(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " : ";
            if (temp->left)
            {
                q.push(temp->left);
                cout << temp->left->val << " ";
            }
            if (temp->right)
            {
                q.push(temp->right);
                cout << temp->right->val << " ";
            }
            cout << endl;
        }
    }

    int minVal(TreeNode *node)
    {
        if (!node)
        {
            return INT_MIN;
        }
        if (node->left == nullptr)
        {
            return node->val;
        }
        return minVal(node->left);
    }
    TreeNode *deleteNode(TreeNode *node, int data)
    {
        if (root == nullptr)
        {
            cout << "No Tree to delete" << endl;
            return nullptr;
        }
        if (node == nullptr)
        {
            cout << "Node not found" << node->val << endl;
            return nullptr;
        }
        // three case needs to be handle
        // 1) Delete leaf node
        // 2) Delete node with only one child
        // 3) delete node , having left and right child
        //      3.1) replace the node value with Min of right subtree

        // CASE -1 leaf node
        if (data < node->val)
        {
            node->left = deleteNode(node->left, data);
        }
        else if (data > node->val)
        {
            node->right = deleteNode(node->right, data);
        }
        else
        {
            // root node
            if (node->left && node->right)
            {
                node->val = minVal(node->right);
                cout << "min value " << node->val;
                node->right = deleteNode(node->right, node->val);
            }
            // leaf node
            else if (!node->left && !node->right)
            {
                delete (node);
                return nullptr;
            }
            // left subtree
            else if (node->left && !node->right)
            {
                TreeNode *temp = node->left;
                node->left = nullptr;
                delete (node);
                return temp;
            }
            // right subtree
            else if (node->right && !node->left)
            {
                TreeNode *temp = node->right;
                node->right = nullptr;
                delete (node);
                return temp;
            }
        }
        return node;
    }

public:
    TreeNode *root = nullptr;

    ~BST()
    {
        delete root;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    void printBst()
    {
        printBst(root);
        cout << endl;
    }

    void printLevel()
    {
        printLevel(root);
    }

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }
};
