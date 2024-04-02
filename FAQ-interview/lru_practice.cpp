#include <bits/stdc++.h>
using namespace std;

class lru
{
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;

    lru(int cap)
    {
        l.clear();
        m.clear();
        capacity = cap;
    }

    int get(int val)
    {
        if (m.find(val) != m.end())
        {
            int return_val = m[val]->second;
            l.erase(m[val]);
            l.push_front({val, return_val});
            m[val] = l.begin();
            return return_val;
        }
        else
        {
            return -1;
        }
    }
    void put(int key, int val)
    {
        if (m.find(key) != m.end())
        {
            l.erase(m[val]);
            l.push_front({key, val});
            m[val] = l.begin();
        }
        // New entry
        else
        {
            if (m.size() == capacity)
            {
                m.erase(l.back().first);
                l.pop_back();
                l.push_front({key, val});
                m[val] = l.begin();
            }
            else
            {
                l.push_front({key, val});
                m[val] = l.begin();
            }
        }
    }

private:
};

int main()
{
    lru *l = new lru(5);
    l->put(1, 1);
    l->put(2, 2);
    l->put(3, 3);
    l->put(4, 4);
    cout << l->get(2) << endl;
    cout << l->get(4) << endl;

    return 1;
}