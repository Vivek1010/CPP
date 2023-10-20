#include <iostream>
#include <queue>
using namespace std;

class MerchOrder
{
private:
    queue<int> basic_q;
    queue<int> pri_q;
    int count_pri = 0;
    int count_basic = 0;

    bool isPriQEmpty()
    {
        return count_pri;
    }

    bool isBasicQEmpty()
    {
        return count_basic;
    }

public:
    void place_order(int &OrderId, bool pri)
    {
        if (pri)
        {
            pri_q.push(OrderId);
            count_pri++;
        }
        else
        {
            basic_q.push(OrderId);
            count_basic++;
        }
    }
    void fulfill_order()
    {

        while (isPriQEmpty())
        {
            cout << "fulfilling priority order: " << pri_q.front() << endl;
            pri_q.pop();
            count_pri--;
        }

        while (isBasicQEmpty())
        {
            cout << "fulfilling basic orders: " << basic_q.front() << endl;
            basic_q.pop();
            count_basic--;
        }
    }
};