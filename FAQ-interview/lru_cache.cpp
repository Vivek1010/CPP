#include<bits/stdc++.h>
using namespace std;
class lru
{
    public:
        list<pair<int,int>> l;
        unordered_map<int, list<pair<int,int>>::iterator> table;
        int capacity;

        lru(int cap)
        {
            l.clear();
            table.clear();
            capacity = cap;
        }

        int get(int key)
        {
            if(table.find(key) != table.end())
            {
                int value = table[key]->second;
                l.erase(table[key]);
                table.erase(key);
                l.push_front({key, value});
                table[key] = l.begin();
                return  value;
            }
            return -1;
        }
        void put (int key, int value)
        {
            // key is laready present
            if (table.find(key) != table.end())
            {
                l.erase(table[key]);
                table.erase(key);
                l.push_front({key, value});
                table[key] = l.begin();
            }
            else {
                if(table.size() == capacity)
                {
                    int key = l.back().first;
                    l.pop_back();
                    table.erase(key);
                }
                l.push_front({key, value});
                table[key] = l.begin();
            }
        }
};


int main()
{
    lru *l =  new lru(3);
    l->put(0,100);
    l->put(1,99);
    l->put(2,98);
    l->put(3,97);
    l->put(4,96);
    l->put(5,95);
    cout << l->get(5) << endl;
    cout << l->get(0) << endl;
    delete l;
    return 1;
}