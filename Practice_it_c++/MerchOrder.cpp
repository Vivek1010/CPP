#include "MerchOrder.hpp"
#include <cstdlib>

int main()
{
    int NoOfOrders = 100;
    MerchOrder order;
    while (NoOfOrders--)
    {
        int orderId = rand() % 1000;
        order.place_order(orderId, (orderId % 2));
    }
    order.fulfill_order();
    return 1;
}