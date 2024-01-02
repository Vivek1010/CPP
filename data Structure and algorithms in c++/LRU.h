#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    int cp = 0;
    struct Node
    {
        int value;
        Node *left;
        Node *right;
        Node(int data)
        {
            value = data;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    unordered_map<int, Node *> m;
    void add(int data)
    {
        if (!head)
        {
            head = new Node(data);
            tail = head;
            //cout << "head is created with " << data << endl;
        }
        else
        {
            Node *temp = new Node(data);
            temp->right = head;
            head->left = temp;
            head = temp;
        }
        size++;
        //cout << "key is added in DB " << data << endl;
    }

    void deleteNode(Node *temp)
    {
        if (!head)
        {
            return;
        }

        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            //cout << "head  == Tail  " << endl;
        }
        else if (temp == tail)
        {
            Node *to_delete = tail;
            Node *pre_delete = tail->left;
            pre_delete->right = nullptr;
            tail = pre_delete;
            delete (to_delete);
            //cout << "deleting tail " << endl;
        }
        else
        {
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            delete temp;
            //cout << "deleting in between " << endl;
        }
        size--;
    }

    void modify(Node *temp, int data)
    {
        temp->value = data;
    }

    int isFull()
    {
        return (size == cp);
    }

public:
    LRUCache(int capacity)
    {
        cp = capacity;
        m.clear();
        head = tail = nullptr;
    }

    int get(int key)
    {

        if (m.find(key) != m.end())
        {
            //cout << " get Key found " << key << endl;
            deleteNode(m[key]);
            add(key);
            return m[key]->value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) == m.end())
        {
            //cout << "Key not found in map" << endl;
            if (isFull())
            {
                //cout << "capacity is full" << endl;
                int to_delete = tail->value;
                deleteNode(tail);
                m.erase(to_delete);
            }
            //cout << "capacity is not  full" << endl;
            add(key);
            m[key] = head;
            //cout << "key " << key << "is added with value " << m[key]->value << endl;
        }
        else
        {
            ///cout << "key found modifying " << key << endl;
            deleteNode(m[key]);
            add(key);
            m[key] = head;
        }
    }
};