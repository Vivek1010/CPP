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
        cout << endl;
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
    void
    prepend(int data)
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

    void
    delete_first()
    {
        if (len == 0)
        {
            cout << "Nothing to delete " << __FUNCTION__ << "()" << endl;
            return;
        }

        Node *temp = head;
        if (len == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete (temp);
        len--;
    }

    Node *
    get(int index)
    {
        Node *temp = head;
        if (index < 0 || index > len)
        {
            cout << "Invalid Index" << endl;
            return nullptr;
        }
        for (int i = 0; i != index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool
    set(int index, int data)
    {
        Node *temp = get(index);
        if (temp)
        {
            temp->data = data;
            return true;
        }
        return false;
    }

    void
    insert(int index, int data)
    {
        if (index <= 0)
        {
            prepend(data);
        }
        else if (index >= len)
        {
            append(data);
        }
        else
        {
            Node *temp = get(index - 1);
            Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            len++;
        }
    }

    void
    delete_node(int index)
    {
        if (index < 0 || index >= len)
        {
            cout << endl
                 << "Invalid index " << __FUNCTION__ << endl;
            return;
        }
        else if (index == 0)
        {
            delete_first();
        }
        else if (index == len - 1)
        {
            delete_last();
        }
        else
        {
            Node *temp = get(index - 1);
            Node *deleteIt = temp->next;
            temp->next = temp->next->next;
            delete (deleteIt);
            len--;
        }
    }

    void
    inplace_reverse()
    {
        if (!head)
        {
            cout << endl
                 << "No linked list" << endl;
            return;
        }
        Node *before = nullptr;
        Node *temp = head;
        Node *after = temp->next;

        for (int i = 0; i < len; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
        Node *temp_h = head;
        head = tail;
        tail = temp_h;
    }

    Node *
    findMiddleNode()
    {
        if (!head)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        if (head->next->next == nullptr)
        {
            return head->next;
        }
        Node *temp = head;
        Node *temp2 = head;
        while (temp2 && temp2->next && temp2->next->next)
        {
            temp = temp->next;
            temp2 = temp2->next->next;
        }
        if ((temp2->next) && (temp2->next->next == NULL))
        {
            return temp->next;
        }
        return temp;
    }
};