#include "Bst.h"
int main()
{
    BST b;
    vector<int> to_insert{5, 1, 2, 3, 4, -1, 6, 7, 8, 9, -20, 100, 45};
    for (auto x : to_insert)
    {
        b.insert(x);
    }
    b.printBst();
    b.printLevel();
    cout << endl
         << "deleting node 1" << endl;
    b.deleteNode(1);
    b.printLevel();
    cout << endl
         << "deleting node 5" << endl;
    b.deleteNode(5);
    b.printLevel();
    cout << endl
         << "deleting node 100" << endl;
    b.deleteNode(100);
    b.printLevel();
    return 1;
}