#include "routeUpdate.hpp"

int main()
{
    routeUpdate route;
    route.add_stop(1);
    route.add_stop(2);
    route.add_stop(3);
    route.add_stop(4);
    route.add_stop(5);
    cout << "current route: " << route.current_stop() << endl;
    route.next_stop();
    cout << "after update current route: " << route.current_stop() << endl;
    route.previous_stop();
     cout << "after prev update current route: " << route.current_stop() << endl;
    return 0;
}