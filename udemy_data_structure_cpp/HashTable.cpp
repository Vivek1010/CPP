#include "HashTable.hpp"

int main()
{
    HashTable *ht = new HashTable();
    ht->set("vivek", 100);
    ht->set("Avi", 1000);
    ht->set("Annpurna", 1090);
    ht->set("Sandeep", 00);
    ht->set("Google", 81999);
    ht->set("Avaya", 1000);
    ht->set("NXT", 1000);
    ht->set("Juniper", 1000);
    ht->set("Cisco", 1000);
    ht->set("Extrem", 1000);
    ht->set("facebook", 1000);
    ht->set("adobe", 99000);
    ht->print();
    cout << "adobe : " << ht->get("adobe") << endl;
    cout << "google : " << ht->get("Google") << endl;
    vector<string> allKeys = ht->keys();
    for (auto str : allKeys)
    {
        cout << str << " ";
    }
    return 1;
}