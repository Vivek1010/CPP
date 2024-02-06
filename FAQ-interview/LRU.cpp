#include "LRU.h"
int main()
{
    LRUCache *t = new LRUCache(2);
    //[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    t->put(1, 2);
    t->put(2, 2);
    cout << t->get(1) << endl;
    t->put(3, 3);
    cout << t->get(2) << endl;
    t->put(4, 4);
    cout << t->get(1) << endl;
    cout << t->get(3) << endl;
    cout << t->get(4) << endl;
    return 1;
}