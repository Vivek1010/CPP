#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    Node(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~Node()
    {
        if (this->left)
        {
            delete this->left;
        }
        if (this->left)
        {
            delete this->right;
        }
        delete this;
    }
};

template <typename T>
class bt
{
private:
    Node<T> *root;
    void insert_int(T data, Node<T> *node)
    {
        if (!node)
        {
            // this->root = new Node<T>(data);
            setRoot(new Node<T>(data));
            cout << "root = " << data << " is created" << endl;
            return;
        }

        if (node->left == nullptr && data < node->data)
        {
            node->left = new Node<T>(data);
            return;
        }
        if (node->right == nullptr && data > node->data)
        {
            node->right = new Node<T>(data);
            return;
        }

        if (data < node->data)
        {
            insert_int(data, node->left);
        }
        else
        {
            insert_int(data, node->right);
        }
    }

    void printT_int(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        printT_int(root->left);
        cout << root->data << " ";
        printT_int(root->right);
    }
    void PyPrint(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left)
        {
            cout << root->left->data << ", ";
        }
        if (root->right)
        {
            cout << root->right->data << ", ";
        }
        cout << endl;
        PyPrint(root->left);
        PyPrint(root->right);
    }

public:
    bt()
    {
        root = nullptr;
    }
    ~bt()
    {
        // TODO
    }
    void insert(T data)
    {
        insert_int(data, (getRoot()));
    }

    void printT()
    {
        printT_int(getRoot());
    }

    void PrettyPrint()
    {
        PyPrint(getRoot());
    }
    void setRoot(Node<T> *temp)
    {
        root = temp;
    }
    Node<T> *takeinputRec(Node<T> *tempNode)
    {
        if (!root)
        {
            cout << "please enter the root " << endl;
            T rootData;
            cin >> rootData;
            root = new Node<T>(rootData);
            tempNode = root;
        }
        if (!tempNode)
        {
            // leaf node case
            return tempNode;
        }

        else
        {
            cout << "Please enter the left child of the " << tempNode->data << "(-1 to set leaf)" << endl;
            T leftData;
            cin >> leftData;
            if (leftData != -1)
            {
                tempNode->left = new Node<T>(leftData);
            }
            else
            {
                tempNode->left = nullptr;
            }
            cout << "Please enter the right child of the " << tempNode->data << "(-1 to set leaf)" << endl;
            T rightData;
            cin >> rightData;
            if (rightData != -1)
            {
                tempNode->right = new Node<T>(rightData);
            }
            else
            {
                tempNode->right = nullptr;
            }
        }
        takeinputRec(tempNode->left);
        takeinputRec(tempNode->right);
        return root;
    }
    Node<T> *takeinputLevel(Node<T> *tempNode)
    {
        if (!root)
        {
            cout << "pleae enter level 0 data(root)" << endl;
            T rootData;
            cin >> rootData;
            root = new Node<T>(rootData);
        }
        queue<Node<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *temp = q.front();
            q.pop();
            cout << "please enter child of  " << temp->data << endl;
            T leftData, rightData;
            cin >> leftData >> rightData;
            if (leftData != -1)
            {
                q.push(temp->left = new Node<T>(leftData));
            }
            if (rightData != -1)
            {
                q.push(temp->right = new Node<T>(rightData));
            }
        }
        return root;
    }
    void printLevel()
    {
        if (!root)
        {
            return;
        }
        queue<Node<T> *> q;
        q.push(root);
        Node<T> *spc = new Node<T>(INT_MIN);
        q.push(spc);
        while (!q.empty())
        {
            Node<T> *temp = q.front();
            if (temp->data == INT_MIN)
            {
                // if queue is not empty them push this to the end
                q.pop();
                if (!q.empty())
                {
                    cout << endl;
                    q.push(spc);
                }
            }
            else
            {
                q.pop();
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    Node<T> *getRoot()
    {
        return this->root;
    }
    int countNode(Node<T> *tempNode)
    {
        if (!tempNode)
        {
            return 0;
        }
        return (1 + countNode(tempNode->left) + countNode(tempNode->right));
    }
    bool find(Node<T> *node, T fdata)
    {
        if (!root)
        {
            cout << "No tree to search" << endl;
            return false;
        }
        if (!node)
        {
            // cout << fdata << " Not found" << endl;
            return false;
        }
        if (fdata == node->data)
        {
            // cout << "data Found in tree" << endl;
            return true;
        }
        if (fdata < node->data)
        {
            return find(node->left, fdata);
        }
        else
        {
            return find(node->right, fdata);
        }
    }
};