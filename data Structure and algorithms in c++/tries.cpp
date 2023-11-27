#include "tries.h"

int main()
{
    tries t;
    t.add("virat");
    t.add("abc");
    t.add("fgh");

    t.add("rachin");
    t.add("dinesh");
    t.add("siraj");

    t.add("new");
    t.add("news");

    t.search("virat");
    t.search("abc");
    t.search("news");
    t.search("new");
    t.search("ne");
    return true;
}