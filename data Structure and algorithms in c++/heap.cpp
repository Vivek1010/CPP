#include "heap.h"

int main()
{
    priorityQueue pq;
    cout << "is Empty= " << pq.isEmpty() << endl;
    cout << "size=  " << pq.getSize() << endl;

    vector<int> to_insert{0,3,1,5,6,7,2,-1,-20};
    for (auto x : to_insert)
    {
        pq.insert(x);
    }
    pq.printPq();
    pq.delMin();
    pq.printPq();
    pq.delMin();
    pq.printPq();
    return 1;
}
