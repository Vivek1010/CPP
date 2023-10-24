#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkList
{
private:
    Node *head;
    Node *tail;
    int len = 0;

public:
    // constructor
    LinkList()
    {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    ~LinkList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
        }
    }
    Node *
    createNode(int data)
    {
        return new Node(data);
    }
    void
    append(int data)
    {
        if (tail)
        {
            tail->next = createNode(data);
            tail = tail->next;
        }
        else
        {
            head = tail = createNode(data);
            tail->next = nullptr;
            head->next = nullptr;
        }
        len++;
    }

    void
    print_list()
    {
        Node *temp = head;
        cout << "LIST : ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    int size()
    {
        return len;
    }
    void
    delete_last()
    {
        // when there is a list
        if (head)
        {
            // and head != tail
            if (head != tail)
            {
                Node *temp = head;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                delete (tail);
                tail = temp;
                tail->next = nullptr;
            }
            // head == tail
            else if (head == tail)
            {
                delete (tail);
                head = tail = nullptr;
            }
            len--;
        }
    }
};