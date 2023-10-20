#include <iostream>
#include <list>
#include <string>
using namespace std;

class routeUpdate
{
private:
    list<int> route;
    list<int>::iterator current = route.begin();

public:
    void
    add_stop(int stop)
    {
        route.push_back(stop);
    }

    void
    next_stop()
    {
        // check if this is the last
        if (current == prev(route.end()))
        {
            current = route.begin();
        }
        else
        {
            advance(current, 1);
        }
    }
    void
    previous_stop()
    {
        if (current == route.begin())
        {
            current = prev(route.end());
        }
        else
        {
            advance(current, -1);
        }
    }

    int
    current_stop()
    {
        return *current;
    }
};