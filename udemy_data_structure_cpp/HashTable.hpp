#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    string name;
    int value;
    Node *next;

    Node(string name, int value)
    {
        this->name = name;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *data[SIZE]{
        nullptr,
    };

public:
    void print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " :";
            if (data[i])
            {
                Node *temp = data[i];
                while (temp)
                {
                    cout << "{ " << temp->name << " : " << temp->value << " }" << endl;
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
    int hash(string name)
    {
        int index = 0;
        int sum = 0;
        for (int i = 0; i < name.length(); i++)
        {
            sum = sum + ((int)name[i] * 23);
        }
        index = sum % SIZE;
        return index;
    }
    void set(string name, int value)
    {
        int index = hash(name);
        Node *newNode = new Node(name, value);
        if (data[index] == nullptr)
        {
            data[index] = newNode;
        }
        else
        {
            Node *temp = data[index];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int get(string key)
    {
        int index = hash(key);
        if (data[index])
        {
            Node *temp = data[index];
            while (temp)
            {
                if (temp->name == key)
                {
                    return (temp->value);
                }
                temp = temp->next;
            }
        }
        return 0;
    }
    vector<string> keys()
    {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++)
        {
            if (data[i])
            {
                Node *temp = data[i];
                while (temp)
                {
                    allKeys.push_back(temp->name);
                    temp = temp->next;
                }
            }
        }
        return allKeys;
    }
};