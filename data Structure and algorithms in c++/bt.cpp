#include "Bt.h"

int main()
{
     cout << "===== Started =======" << endl;

     bt<int> b;
     /*
     b.insert(6);
     b.insert(4);
     b.insert(7);
     b.insert(1);
     b.insert(8);
     b.insert(9);
     b.insert(10);
     b.insert(-1);
     b.setRoot(b.takeinputRec(nullptr));
     */
     /// input 10 5 20 3 6 10 30 -1 -1 -1 -1 -1 -1 -1 -1
     /// 1 2 3 4 5 6 -10 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
     /// 1 2 3 -4 -1 -1 -1 -1 -1
     b.setRoot(b.takeinputLevel(nullptr));
     b.printT();
     cout << endl;
     b.PrettyPrint();
     b.printLevel();
     cout << "No of Nodes= " << b.countNode(b.getRoot());
     int fdata = 10;
     if (b.find(b.getRoot(), fdata) == true)
     {
          cout << endl
               << fdata << " found" << endl;
     }
     else
     {
          cout << endl
               << fdata << " Not found" << endl;
     }
     cout << endl
          << "MinValue = " << b.findMin(b.getRoot());

     cout << "find Min from Bt = " << b.findMinfromBt(b.getRoot()) << endl;
     int count = 0;
     cout << "Leaf node = " << b.countLeafNode(b.getRoot(), count);
     cout << endl
          << "=====Path=====" << endl;
     b.getPath(b.getRoot(), 5);
     return 1;
}