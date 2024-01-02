#include "LRU.h"
int main()
{
    LRUCache lRUCache(1);
    lRUCache.put(1, 1);              // cache is {1=1}
    lRUCache.put(2, 2);              // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // return 1
    lRUCache.put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // returns -1 (not found)
    lRUCache.put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // return -1 (not found)
    cout << lRUCache.get(3) << endl; // return 3
    cout << lRUCache.get(4) << endl; // return 4
    cout << lRUCache.get(5) << endl; // return 4
    return 1;
}
