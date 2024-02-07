#include "linkedList.h"

int main()
{
    LL *l = new LL();
    for (int i = 0; i < 100; i++)
    {
        l->insert(i);
    }
    cout << "Original " << endl;
    l->printLL();
    cout << "Reversed " << endl;
    l->reverse();

    l->printLL();
    delete l;
    return 1;
}

/// @brief
/// @param data
void LL::insert(int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        return;
    }
    Node *runner = head;
    while (runner->next)
    {
        runner = runner->next;
    }
    runner->next = new Node(data);
}

/// @brief
void LL::printLL()
{
    Node *runner = head;
    while (runner)
    {
        cout << runner->data << " -> ";
        runner = runner->next;
    }
}
void LL::reverse()
{
    if (head == nullptr || head->next == nullptr) 
    { 
        return; 
    }

    Node* prev = nullptr;
    Node* temp = head;
    Node* nxt = nullptr;
    while(temp)
    {
        nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    head = prev;
}