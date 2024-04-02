#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(Node *head, Node *tail, int val)
{
    Node *temp = new Node(val);
    // first Node
    if (head->next == NULL)
    {
        head->next = temp;
        tail->next = temp;
    }
    else
    {
        tail->next->next = temp;
        tail->next = temp;
    }
}

void printLL(Node *head)
{
    Node *runner = head->next;
    while (runner)
    {
        cout << runner->data << " ";
        runner = runner->next;
    }
}

void deleteNode(Node *head, int val)
{
    Node *runner = head;
    while (runner->next)
    {
        if (runner->next->data == val)
        {
            Node *temp = runner->next;
            runner->next = runner->next->next;
            delete temp;
            cout << "found deleted" << val << endl;
            return;
        }
        runner = runner->next;
    }
    cout << " Not found " << val << endl;
    return;
}
int main()
{
    Node *head = new Node();
    Node *tail = new Node();
    for (int i = 0; i < 10; i++)
    {
        insert(head, tail, i);
    }
    printLL(head);
    deleteNode(head, 0);
    cout << "\nAfter delete\n";
    printLL(head);
    return 1;
}