#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
struct Node
{
    K key;
    V value;
    Node *next;
    Node(K k, V v)
    {
        this->key = k;
        this->value = v;
        Node *next = nullptr;
    }
};

template <typename K, typename V>
class myMap
{
public:
    myMap()
    {
        /// allocate the memory and initialise it.
        bucket = new Node<K, V> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            bucket[i] = nullptr;
        }
    }
    bool insert(string key, int value)
    {
        return insertBucket(bucket, bucketSize, key, value);
    }

    void printMap()
    {
        cout << endl
             << "MAP" << endl;
        for (int i = 0; i < bucketSize; i++)
        {
            Node<K, V> *temp = bucket[i];
            while (temp)
            {
                cout << "key -> " << setw(20) << temp->key << " ,value -> " << temp->value << endl;
                temp = temp->next;
            }
        }
    }
    int getCount() { return count; }
    bool remove(K key)
    {
        // get the index;
        int bucketIndex = getIndex(key, bucketSize);
        Node<K, V> *temp = bucket[bucketIndex];
        Node<K, V> *prev = nullptr;
        while (temp)
        {
            // case >> 1 remove head
            if (bucket[bucketIndex] == temp && temp->key == key)
            {
                Node<K, V> *del = temp;
                bucket[bucketIndex] = temp->next;
                delete del;
                count--;
                return true;
            }

            // case >> 2 delete last node
            if (temp->next == nullptr && temp->key == key)
            {
                Node<K, V> *del = temp;
                prev->next = nullptr;
                delete del;
                count--;
                return true;
            }

            // case >> 3 inbetween node has be deleted
            if (temp->key == key)
            {
                Node<K, V> *del = temp;
                prev->next = temp->next;
                count--;
                delete del;
            }
            prev = temp;
            temp = temp->next;
        }
    }

private:
    // lets start bucket size with 10;
    int bucketSize = 10;

    /// @brief bucket is the array
    Node<K, V> **bucket;
    int count = 0;

    int getIndex(K key, V size)
    { /// hash code function
        /// prime no 29 is taken as base
        /// to have better distribution
        int base = 29;
        int index;
        for (int i = (key.size() - 1); i >= 0; i--)
        {
            index = key[i] + (index * base);
            index = index % size;
        }
        // cout << "index = " << index << endl;
        return index % size;
    }

    /// @brief this is helper function now
    /// @param p_bucket array which needs to be modifed
    /// @param b_size   bucket size
    /// @param key      key for noe
    /// @param value    vlaue for now
    /// @return         sccess or failure

    bool insertBucket(Node<K, V> **(&p_bucket), int b_size, K key, V value)
    {
        // get the index;
        int bucketIndex = getIndex(key, b_size);
        // create node
        Node<K, V> *newNode = new Node<K, V>(key, value);
        /// If bucketIndex is empty put the node.
        if (p_bucket[bucketIndex] == nullptr)
        {
            p_bucket[bucketIndex] = newNode;
        }
        else
        {
            /// search and insert at the end (O(n));
            Node<K, V> *temp = p_bucket[bucketIndex];
            Node<K, V> *prev = nullptr;
            while (temp != nullptr)
            {
                if (key == temp->key)
                {
                    cout << "same key = " << key << endl;
                    return false;
                }
                prev = temp;
                temp = temp->next;
            }
            // last node
            prev->next = newNode;
        }
        count++;
        float loadFactor = (1.0 * count) / b_size;
        if (loadFactor >= 0.7)
        {
            cout << "Load Factor = " << loadFactor << endl;
            cout << endl
                 << "Before  reshash count " << count << endl;
            count = 0;
            reHash();
        }
        cout << "Successfully inserted at index = " << bucketIndex << endl;
        // printMap();
        return true;
    }

    /// @brief - when load factor gets increased from 0.7
    ///          function get executed.
    void reHash()
    {
        cout << "rehashing started  bucketSize = " << bucketSize << endl;
        int newBucketSize = bucketSize * 2;
        Node<K, V> **newBucket = new Node<K, V> *[newBucketSize];
        // count = 0;
        for (int i = 0; i < bucketSize; i++)
        {
            Node<K, V> *temp = bucket[i];
            while (temp != nullptr)
            {
                insertBucket(newBucket, newBucketSize, temp->key, temp->value);
                temp = temp->next;
            }
        }
        Node<K, V> **del = bucket;
        bucket = newBucket;
        bucketSize = newBucketSize;
        delete[] del;
        cout << "after reshash count " << count << endl;
    }
};