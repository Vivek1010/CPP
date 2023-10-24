#include "LinkList.hpp"

int main()
{
    LinkList ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    ll.print_list();
    ll.delete_last();
    ll.delete_last();
    ll.delete_last();
    ll.delete_last();
    ll.delete_last();
    ll.delete_last();
    ll.print_list();
    return 0;
}