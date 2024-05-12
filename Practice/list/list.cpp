#include <iostream>
using namespace std;

#define PASS 0;
#define FAIL 1;

struct node
{
    int data;
    node *next;

    node(int data_pass, node *tail)
    {
        data = data_pass;
        next = tail;
    }
    node(int data_pass)
    {
        data = data_pass;
        next = nullptr;
    }
};

int insert(node *head, node *tail, int data)
{
    if (head->next == tail)
    {
        head->next = new node(data, tail);
    }
    else
    {
        node *temp = head->next;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = new node(data, tail);
    }
    return PASS;
}

int delete_node(node *head, node *tail, int data)
{
    node *temp = head->next;
    while (temp->next != tail && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp->next != tail)
    {
        node *to_delete = temp->next;
        temp->next = temp->next->next;
        delete to_delete;
        return PASS;
    }
    cout << data << " Not Found in list";
    return FAIL;
}
int main(int argc, char *argv[])
{
    //
    // first create the tail
    //
    node *tail = new node(0);
    node *head = new node(0);
    head->next = tail;
    if (argc > 1)
    {
        auto no_of_element = atoi(argv[1]);
        while (no_of_element--)
        {
            int data_pass = rand() % 100;
            (insert(head, tail, data_pass))
                ? (cout << data_pass << " insert fail \n")
                : (cout << data_pass << " inserted sucessfully \n");
        }
    }
    else
    {
        cout << " USAGE: ./a.out  <no of item to be inserted> \n";
    }

    exit(EXIT_SUCCESS);
}