#include "tree.hpp"
int main()
{
    BSTtree bt;
    bt.insert(10) ? cout << "inserted 6" << endl : cout << "Not inserted";
    bt.insert(1) ? cout << "inserted 1" << endl : cout << "Not inserted";
    bt.insert(3) ? cout << "inserted 3" << endl : cout << "Not inserted";
    bt.insert(7) ? cout << "inserted 7" << endl : cout << "Not inserted";
    bt.insert(60) ? cout << "inserted 6" << endl : cout << "Not inserted";
    bt.insert(700) ? cout << "inserted 1" << endl : cout << "Not inserted";
    bt.insert(-1) ? cout << "inserted 3" << endl : cout << "Not inserted";
    bt.insert(70) ? cout << "inserted 7" << endl : cout << "Not inserted";
    bt.insert(-6) ? cout << "inserted 1" << endl : cout << "Not inserted";
    bt.insert(-10) ? cout << "inserted 3" << endl : cout << "Not inserted";
    bt.insert(43) ? cout << "inserted 7" << endl : cout << "Not inserted";
    //  cout << bt.insert(2);
    //  cout << bt.insert(3);
    //   cout << endl
    //        << "root vlaue " << bt.getRoot()->value << " "
    //        << "left = " << bt.getRoot()->left->value << " " << endl;
    //<< "right = " << bt.getRoot()->right->value;
    // bt.root = new Node(10);
    // bt.root->left = new Node(5);
    // bt.root->left->left = new Node(2);
    // bt.root->right = new Node(20);
    bt.print();
    bt.serach(7000) ? cout << endl
                           << "found 7000"
                    : cout << endl
                           << "Not found" << endl;
    return 1;
}