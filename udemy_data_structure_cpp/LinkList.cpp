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

    ll.append(10);
    ll.append(20);
    ll.append(30);
    ll.print_list();

    ll.delete_last_v2();
    ll.delete_last_v2();
    ll.print_list();

    ll.delete_last_v2();
    ll.print_list();
    ll.delete_last_v2();
    ll.prepend(9);
    ll.prepend(8);
    ll.prepend(7);
    ll.print_list();
    return 0;
}