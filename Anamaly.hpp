#include <iostream>
#include <list>
using namespace std;

class anamaly
{
private:
    list<int> llist;

public:
    void add_reading(int &data)
    {
        llist.push_back(data);
    }
    void smooth_data()
    {
        // get the average
        double sum = 0;
        for (int it : llist)
        {
            sum += it;
        }
        auto avg = sum / llist.size();
        cout << endl
             << "avrage : " << avg << endl;

        // list<int>::iterator temp = llist.begin(); // pointin to the head
        for (auto temp = llist.begin(); temp != llist.end(); ++temp)
        {
            if (*temp > (2 * avg) || *temp < (2 * avg))
            {
                // delete form the head
                if (temp == llist.begin())
                {
                    llist.pop_front();
                    temp = llist.begin();
                }
                // delete end
                else if (temp == prev(llist.end()))
                {
                    llist.pop_back();
                    break;
                }
                // delete in between
                else
                {
                    auto nxt = next(temp);
                    llist.erase(temp);
                    temp = nxt;
                }
            }
        }
    }
    void print_data()
    {
        for (int i : llist)
        {
            cout << i << " ";
        }
    }
};