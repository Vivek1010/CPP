#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    vector<struct Node *> child;
    Node(T data)
    {
        this->data = data;
    }
    ~Node()
    {
        for (int i = 0; i < this->child.size(); i++)
        {
            delete this->child[i];
        }
    }
};

template <typename T>
class TreeNode
{
public:
    Node<T> *root = nullptr;

    Node<T> *getRoot()
    {
        return root;
    }
    void setRoot(Node<T> *root)
    {
        this->root = root;
    }

    bool insert(T data)
    {
        if (!root)
        {
            root = new Node<T>(data);
            return true;
        }
        root->child.push_back(new Node<T>(data));
        return true;
    }
    void printTree(struct Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << ":";

        for (int i = 0; i < root->child.size(); i++)
        {
            cout << root->child[i]->data << ",";
        }
        cout << endl;
        for (int i = 0; i < root->child.size(); i++)
        {
            printTree(root->child[i]);
        }
    }
    // Construct the tree and return the root
    Node<T> *takeInput()
    {
        cout << "Please enter the data" << endl;
        T rootData, numberOfChild;
        cin >> rootData;
        Node<T> *newNode = new Node<T>(rootData);
        cout << "Please enter how many childrens are there for " << newNode->data << endl;
        cin >> numberOfChild;
        for (int i = 0; i < numberOfChild; i++)
        {
            // cout << "please enter the data for childerns" << endl;
            newNode->child.push_back(takeInput());
        }
        root = newNode;
        return root;
    }

    Node<T> *takeInputLevel()
    {
        queue<Node<T> *> q;
        int rootData;
        cout << "Enter the root Node" << endl;
        cin >> rootData;
        root = new Node<T>(rootData);
        q.push(root);
        while (!q.empty())
        {
            // create
            Node<T> *front = q.front();
            q.pop();
            cout << "how many childrens for " << front->data << endl;
            T numberofChildren = 0;
            cin >> numberofChildren;
            for (int i = 1; i <= numberofChildren; i++)
            {
                T children;
                cout << "enter the " << i << " th child of " << front->data << endl;
                cin >> children;
                Node<T> *newNode = new Node<T>(children);
                front->child.push_back(newNode);
                q.push(newNode);
            }
        }
        return root;
    }
    void printLevels()
    {
        cout << endl
             << "------Level Wise print-----" << endl;
        if (!root)
        {
            return;
        }
        queue<Node<T> *> q;
        q.push(root);
        cout << "Level 0:" << root->data << endl;
        int level = 0;
        while (!q.empty())
        {
            Node<T> *front = q.front();
            q.pop();
            level++;
            cout << "Level " << level << ":";
            for (int i = 0; i < front->child.size(); i++)
            {
                q.push(front->child[i]);
                cout << front->child[i]->data << " ";
            }
            cout << endl;
        }
    }
    int countNode(Node<T> *root)
    {
        /// if condition is optional
        if (!root)
        {
            return 0;
        }
        int smallAns = 1;
        for (int i = 0; i < root->child.size(); i++)
        {
            smallAns += countNode(root->child[i]);
        }
        return smallAns;
    }

    int Height(Node<T> *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < root->child.size(); i++)
        {
            int sbHight = 1 + Height(root->child[i]);
            ans = max(ans, sbHight);
        }
        return ans + 1;
    }

    void printDepthLevel(int depth)
    {
        if (!root)
        {
            return;
        }
        if (depth == 0)
        {
            cout << root->data;
            return;
        }
        queue<Node<T> *> q;
        q.push(root);
        int localDepth = 1;
        while (!q.empty())
        {
            Node<T> *f = q.front();
            q.pop();
            for (int i = 0; i < f->child.size(); i++)
            {
                if (localDepth == depth)
                {
                    cout << f->child[i]->data << " ";
                }
                else
                {
                    q.push(f->child[i]);
                    localDepth++;
                }
            }
        }
    }

    int countLeafNode(Node<T> *root)
    {
        int ans = 0;
        if (root->child.size() == 0)
        {
            return 1;
        }
        else
        {
            for (int i = 0; i < root->child.size(); i++)
            {
                ans += countLeafNode(root->child[i]);
            }
        }
        return ans;
    }
    void preOrderTrave(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->data << " ";
        for (int i = 0; i < root->child.size(); i++)
        {
            preOrderTrave(root->child[i]);
        }
    }

    void deleteTree(Node<T> *root)
    {
        if (root->child.size() == 0)
        {
            delete root;
            return;
        }
        for (int i = 0; i < root->child.size(); i++)
        {
            deleteTree(root->child[i]);
        }
    }

private:
};