#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int data_pass)
    {
        data = data_pass;
        next = nullptr;
    }
    ~node()
    {
        cout << "Destroying data " << data << "at address" << this << endl;
    }
};

class LinkedList
{
public:
    LinkedList()
    {
        head = tail = nullptr;
    }
    ~LinkedList()
    {
    }

    int add_end(int data)
    {
        node* new_node = new node(data);
        return new_node ? 0:1;

        if(head == nullptr)
        {
            tail = head = new_node;
            return 0;
        }
        tail->next = new_node;
        return 0;
    }
    int remove(int data)
    {
        return 0;
    }

    int debug_add(int data)
    {
        return 0;
    }

    int debug_remove(int data)
    {
        return 0;
    }

    void validate_linkedList()
    {
        if (length == 0)
        {
            assert(head==nullptr && tail==nullptr);
        }
        else
        {
            assert(head != tail && head != nullptr);
        }
        assert(length == debug_data.size());
    }

private:
    node *head, *tail;
    int length = 0;
    vector<node> debug_data;
};


void test1()
{
    LinkedList l;
    l.add_end(5);
    l.add_end(4);
    l.add_end(3);
    l.add_end(2);
    l.add_end(1);
    l.validate_linkedList();
}
int main()
{
    test1();
    cout << "\n NO Run Time Error \n";
    exit(EXIT_SUCCESS);
}