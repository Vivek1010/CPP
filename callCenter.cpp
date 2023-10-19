#include "CallCenter.hpp"

int main()
{
    CallCenter cc;
    double callId;
    int x = 100;
    int limit = x;
    while (x--)
    {
        callId = rand() % limit;
        cc.receive_call(callId);
    }
    while (cc.isEmpty())
        cc.process_call();
    // cc.process_call();

    return 1;
}