#include "bits/stdc++.h"
using namespace std;

class LRUCache
{
public:
    list<pair<int, int>> l;
    map<int, list<pair<int, int>>::iterator> m;
    int _capacity = 0;

    LRUCache(int capacity)
    {
        _capacity = capacity;
        m.clear();
        l.clear();
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        else
        {
            // int remove_value = m[key]->second;
            l.erase(m[key]);
            l.push_front({m[key]->first, m[key]->second});
            m[key] = l.begin();
            return m[key]->second;
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) == m.end())
        {
            if (l.size() == _capacity)
            {
                cout << "capacity full" << endl;
                int remove_key = l.back().second;
                l.pop_back();
                m.erase(remove_key);
            }
            cout << "Not found. ADiing key " << key << " value " << value << endl;
            l.push_front({key, value});
            m[key] = l.begin();
        }
        else
        {
            cout << " found. ADiing key " << key << "value" << value << endl;
            l.erase(m[key]);
            l.push_front({key, value});
            m[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Following solution is having TLE
/*


       if(m.find(key) == m.end())
       {
           return -1;
       }
       else {
           l.remove(key);
           l.push_front(key);
           return m[key];
       }

   }

   void put(int key, int value) {
       if(m.find(key) == m.end())
       {
           if(l.size() == _capacity)
           {
               int last_key = l.back();
               l.pop_back();
               m.erase(last_key);
           }
           m[key] = value;
           l.push_front(key);
       }
       else
       {

           l.remove(key);
           l.push_front(key);
            m[key] = value;

       }

   }
   */
/* Implimentaion is crashing -> Nedd to debug
int get(int key) {
    if(m.find(key) == m.end())
    {
        return -1;
    }
    int return_value = *m[key];
    cout << " get return key " << key <<  " value  " << return_value << endl;
    l.erase(m[key]);
    m.erase(return_value);

    l.push_front(return_value);
    m[key] = l.begin();
    return return_value;
}

void put(int key, int value) {
    if(m.find(key) == m.end())
    {

        if(l.size() == _capacity)
        {
            //remove from list and map
            int lru_entry = l.back();
            l.pop_back();
            cout << "capcity is full removing " <<  lru_entry << endl;
            m.erase(lru_entry);

        }
        //add new entry in map and list
        cout << "adding  entry " << key <<"value" << value <<endl;
        l.push_front(value);
        m[key] = l.begin();

    }
    else
    {
        cout << "Existing entry " << key <<"value" << value <<endl;
        int return_value = *m[key];
        l.erase(m[key]);
        m.erase(return_value);
        l.push_front(return_value);
        m[key] = l.begin();
    }
}
*/