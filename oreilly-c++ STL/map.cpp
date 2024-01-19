#include <bits/stdc++.h>
using namespace std;

struct obj
{
    int x;
    int y;
    int z;
    obj(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
template <typename T, typename X>
void checkMap(T it, X isInserted)
{
    if (isInserted)
    {
        cout << "inserted in the map" << endl;
    }
    else
    {
        cout << it->first << "is present in the map" << endl;
    }
}
int main()
{
    map<string, struct obj> m;
    struct obj o(3, 4, 5);
    auto [it, isInserted] = m.insert({"first", obj(1,2,4)});
    // checkMap(it, isInserted);
    auto [it1, isInserted1] = m.insert({"second", o});
    //checkMap(it, isInserted);
    if ( m.find("second") != m.end())
    {
        //cout << " second "<< m["second"] << " " << endl;
    }

    for(auto &x : m)
    {
        cout<< x.first << "-> " << x.second.x <<endl;
    }

    return 1;
}