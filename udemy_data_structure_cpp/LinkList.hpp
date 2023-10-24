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
        // when there is no list
        else
        {
            cout << "nothing to delete" << endl;
            return;
        }
    }
    // delete from the last
    void
    delete_last_v2()
    {
        // when there is no linked list
        if (len == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        Node *temp = head;
        if (len == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            // core case where list is having more than 1 node
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete (temp);
        len--;
    }

    // add data from the begining
    void prepend(int data)
    {
        Node *temp = createNode(data);
        if (len == 0)
        {
            head = tail = temp;
            head->next = nullptr;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        len++;
    }
};