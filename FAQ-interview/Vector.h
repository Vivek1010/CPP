#include <iostream>
using namespace std;

class Vector
{

public:
    Vector()
    {
        arr = new int[8];
        _capacity = 8;
    }
    ~Vector()
    {
        delete []arr;
    }
    void push_back(int entry);
    int front();
    int back();
    void push_front(int entry);
    int at(int idx) { return arr[idx]; }

private:
    // int getSize() { return _size; }
    int getIndex() { return _NextIdx; }
    int getCapcity() { return _capacity; }
    // void increaseSize() { _size++; }
    void add(int ent)
    {
        arr[getIndex()] = ent;
        _NextIdx++;
    }
    void allocate_more()
    {
        int *temp = new int[_capacity * 2];
        _capacity = _capacity * 2;

        for (int i = 0; i < getIndex(); i++)
        {
            temp[i] = arr[i];
        }
        swap(arr,temp);
        delete []temp;
    }

    int *arr;
    int _NextIdx = 0;
    int _capacity = 0;
};