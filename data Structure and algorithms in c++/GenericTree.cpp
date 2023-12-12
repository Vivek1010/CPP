#include "GenricTree.h"
int main()
{
    cout << "----start-----" << endl;

    TreeNode<int> t;
    // t.setRoot(t.takeInput());
    t.setRoot(t.takeInputLevel());
    t.printTree(t.getRoot());
    t.printLevels();
    cout << "Count = " << t.countNode(t.getRoot()) << endl;
    cout << "Height= " << t.Height(t.getRoot()) << endl;
    t.printDepthLevel(1);
    cout << endl
         << "Leaf node = " << t.countLeafNode(t.getRoot()) << endl;

    t.preOrderTrave(t.getRoot());
    t.deleteTree(t.getRoot());
    return 1;
}