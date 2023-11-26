#include <iostream>
#include "hashmap.h"
using namespace std;

int main()
{
    myMap<string, int> mm;
    mm.insert("a", 1);
    mm.insert("b", 2);
    mm.insert("c", 3);
    mm.insert("d", 4);
    mm.insert("e", 5);
    mm.insert("f", 6);
    mm.insert("g", 7);
    mm.insert("h", 8);
    mm.insert("i", 9);
    mm.insert("j", 10);
    mm.insert("k", 11);
    mm.insert("l", 12);
    mm.insert("m", 13);
    mm.insert("n", 14);
    mm.insert("o", 15);
    mm.insert("p", 16);
    mm.insert("q", 17);
    mm.insert("r", 18);
    mm.insert("s", 19);
    mm.insert("t", 20);
    mm.insert("u", 21);
    mm.insert("v", 22);
    mm.insert("w", 23);
    mm.insert("x", 24);
    mm.insert("y", 25);
    mm.insert("z", 26);
    cout << endl
         << "count" << mm.getCount() << endl;
    mm.printMap();
    mm.remove("a");
    mm.remove("b");
    mm.remove("c");
    mm.remove("d");
    mm.remove("e");
    mm.remove("f");
    mm.remove("g");
    mm.remove("h");
    mm.remove("i");
    // mm.insert("abc", 123) ? std::cout << "insert Done" << endl : cout << "insert fail" << end;
    // mm.insert("def", 456) ? std::cout << "insert Done" << endl : cout << "insert fail" << end;
    mm.printMap();
    cout << endl
         << "count" << mm.getCount() << endl;
    return 1;
}