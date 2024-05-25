#include <thread>
#include "singleton.hpp"

using namespace std;

singleton *singleton::inst = nullptr;
mutex singleton::mtx;

void s1_print()
{
    singleton *s1 = singleton::getinstace();
    s1->print("From s1");
}
void s2_print()
{
    singleton *s2 = singleton::getinstace();
    s2->print("From s2");
}

int main()
{
    thread t1(s1_print);
    thread t2(s2_print);
    t1.join();
    t2.join();
    return 0;
}
