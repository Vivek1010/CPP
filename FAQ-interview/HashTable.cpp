#include <bits/stdc++.h>
using namespace std;
class hashTable
{
    public:
        int capacity;
        vector< list< pair<int,string> > > table;

        hashTable(int size)
        {
            capacity = size;
            table.resize(capacity);
            table.clear();
        }

        void insert(int key, string value)
        {
            int index  = hash(key);
            table[index].push_back({key,value});
        }

        string get(int key)
        {
            int index  = hash(key);
            for(auto it : table[index])
            {
                if (key == it.first)
                {
                   return it.second;
                }
            }
            return NULL;
        }
        void deleteKey(int key)
        {
            int index  = hash(key);
            for (auto it = table[index].begin(); it != table[index].end(); it++)
            {
                if(it->first == key)
                {
                    table[index].erase(it);
                }
            }
        }
    private:
        int hash(int key )
        {
            return key % capacity;
        }
};

int main()
{
    hashTable *h = new hashTable(50);

    h->insert(1, "vivek");
    h->insert(2, "vivek1");
    h->insert(3, "vivek2");
    h->insert(4, "vivek3");
    h->insert(45, "vivek4");
    cout << h->get(45) <<endl;
    delete h;
    return 1;
}