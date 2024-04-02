#include <bits/stdc++.h>
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
    Node()
    {
        next = NULL;
    }
};

void insert(Node *head, Node *tail, int val)
{
    Node *temp = new Node(val);
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
void printll(Node *head)
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
    if (head->next == NULL)
    {
        return;
    }
    Node *runner = head;
    while (runner->next)
    {
        if (runner->next->data == val)
        {
            if (runner == head)
            {
                Node *toDelete = head->next;
                head->next = head->next->next;
                delete toDelete;
            }
            else
            {
                Node *toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
            }
            return;
        }
        runner = runner->next;
    }
}

void find(Node *head, int val)
{
    while (head)
    {
        if (head->data == val)
        {
            cout << "\nfound\n";
            return;
        }
        head = head->next;
    }
    cout << "\nnot found\n";
}
int main()
{
    Node *head = new Node();
    Node *tail = new Node();
    vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int in : input)
    {
        insert(head, tail, in);
    }
    printll(head);
    random_shuffle(input.begin(), input.end());
    for (int in : input)
    {
        // deleteNode(head, in);
    }

    cout << "\nafter delete \n";
    printll(head);
    find(head, 9);
    return 1;
}