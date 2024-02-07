#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    ~Node()
    {
        delete this->next;
    }
};

class LL {

    public:
    Node *head;
    LL()
    {
            Node *head = nullptr;
    }
    ~LL()
    {
        delete head;
    }
        void insert(int data);
        void printLL();
        void reverse();
    private:

};
