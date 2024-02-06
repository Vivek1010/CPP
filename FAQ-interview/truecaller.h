#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 0 - 9 number
#define SIZE 10
struct Node
{
    char data;
    Node *child[SIZE];
    string name;
    bool isTerminal;

    Node()
    {
        isTerminal = false;
        for (int idx = 0; idx < SIZE; idx++)
        {
            child[idx] = nullptr;
        }
    }
    ~Node()
    {
        for (int idx = 0; idx < SIZE; idx++)
        {
            if (this->child[idx])
            {
                delete this->child[idx];
            }
        }
    }
};

class truecaller
{
public:
    Node *root = nullptr;
    bool insert(string phNumber, string name);
    string search(string phNumber);

    // constructor
    truecaller()
    {
        root = new Node(); 
    }

    // Destructor
    ~truecaller()
    {
        delete root;
    }

private:
};