#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 3
struct Node
{
    char data;
    Node *child[SIZE];
    Node(char val)
    {
        data = val;
        for(int i = 0; i<SIZE; i++)
        {
            child[i] = nullptr;
        }
    }
    ~Node()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if(this->child[i])
            {
                delete child[i];
            }
        }
    }
};

class TTree
{
public:
    vector<char> arr{'I', 'A', 'M', 'A', 'T', 'R', 'E', 'Z', 'I'};
    Node *root = nullptr;
   
    TTree()
    {
        
    }
    ~TTree()
    {
        delete root;
    }
    void buildTree();
    void printTree();

private:
    queue<Node*> q;
    int idx = 0; //array index
};