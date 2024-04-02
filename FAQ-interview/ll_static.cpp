#include <bits/stdc++.h>
#include <vector>
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
    // First Node
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
                Node *temp = runner->next;
                head->next = head->next->next;
                // cout << "at head found deleted " << endl;
                delete temp;
            }
            else
            {
                Node *temp = runner->next;
                runner->next = runner->next->next;
                // cout << "between found deleted " << endl;
                delete temp;
            }
            return;
        }
        runner = runner->next;
    }
    if (runner == NULL)
    {
        cout << " Not found" << endl;
    }
}
int main()
{
    Node *head = new Node();
    Node *tail = new Node();
    vector<int> input{};

    for (int i = 0; i < 10; i++)
    {
        input.push_back(rand() % 1000);
    }
    for (int in : input)
    {
        insert(head, tail, in);
    }
    printll(head);
    // random_shuffle(input.begin(), input.end());
    for (int in : input)
    {
        deleteNode(head, in);
    }
    cout << "\nafter delete\n";
    printll(head);
    return 1;
}