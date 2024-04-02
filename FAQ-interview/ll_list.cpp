#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *temp = head;
    if (temp == NULL)
    {
        head = new Node(val);
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(val);
}


void printll(Node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    printll(head);
    return 1;
}