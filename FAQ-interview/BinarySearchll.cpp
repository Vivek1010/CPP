/// Binary Search on linked list
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int calLength(Node* start, Node* end)
{
    int len;
    while(start != end)
    {
        len++
        start = start->next;
    }
    return len+1;
}
int findMissingNde(Node* head)
{
    int lenth = 0
    int low = 0;
    int mid = 0;
    int high = 0;
    Node* runner = head;

    while(runner)
    {
        length++;
        runner = runner->next;
    }
    high = length;
    mid = ((high-low) +1) / 2;

    while()

    while(low < high)
    {
        int len = calLength()
    }


}
void main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    cout << findMissingNde(head);

}