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
    // ll.prepend(8);
    // ll.prepend(7);
    ll.print_list();

    ll.prepend(4);
    ll.prepend(5);
    ll.prepend(6);
    ll.delete_first();
    ll.print_list();
    ll.delete_first();

    ll.prepend(4);
    ll.prepend(5);
    ll.prepend(6);
    ll.print_list();
    cout << "returning at 2 " << ll.get(2)->data << endl;
    cout << "returning at 0 " << ll.get(0)->data << endl;
    cout << "setting 100 at index 0 " << ll.set(0, 100) << endl;
    ll.print_list();
    cout << "setting 200 at index 2 " << ll.set(2, 200) << endl;
    ll.print_list();
    cout << endl;
    cout << "Testing insert function" << endl;
    cout << "========================" << endl;
    ll.insert(0, -5);
    ll.print_list();
    ll.insert(10, 500);
    ll.print_list();
    ll.insert(2, 1000);
    ll.print_list();

    cout << endl;
    cout << "Testing delete_node function" << endl;
    cout << "========================" << endl;
    ll.print_list();
    ll.delete_node(0);
    ll.print_list();
    ll.delete_node(6);
    ll.print_list();
    ll.delete_node(3);
    ll.print_list();

    cout << endl;
    cout << "Testing inplace reverse function" << endl;
    cout << "========================" << endl;
    ll.insert(10, 87);
    ll.insert(0, 97);
    ll.print_list();
    cout << "SIZE: " << ll.size() << endl;
    ll.inplace_reverse();
    ll.print_list();
    return 0;
}