#include <bits/stdc++.h>
using namespace std;

class priorityQueue
{
private:
    vector<int> pq;

public:
    bool isEmpty()
    {
        return (pq.size() == 0);
    }

    int getSize()
    {
        return pq.size();
    }

    int getmin()
    {
        if (!isEmpty())
        {
            return pq[0];
        }
        return INT_MAX;
    }

    void delMin()
    {
        // swap with last element
        swap(pq[0], pq[pq.size() - 1]);
        // pq.erase(pq.end()-1);
        pq.pop_back();
        //printPq();
        // down heapify, min Heap
        int rootIndex = 0;
        int lchildIndex = 1;
        int rchildIndex = 2;
        int childIndex = rootIndex;
        if (pq[lchildIndex] < pq[rchildIndex] && 
            lchildIndex < pq.size()-1)
        {
            childIndex = lchildIndex;
        }
        else if (rchildIndex < pq.size() - 1)
        {
            childIndex = rchildIndex;
        }

        while (rootIndex < (pq.size() - 1))
        {
            if (pq[rootIndex] > pq[childIndex])
            {
                swap(pq[rootIndex], pq[childIndex]);
                rootIndex = childIndex;
                lchildIndex = (2 * rootIndex) + 1;
                rchildIndex = (2 * rootIndex) + 2;
                if (pq[lchildIndex] < pq[rchildIndex])
                {
                    childIndex = lchildIndex;
                }
                else if (rchildIndex < pq.size() - 1)
                {
                    childIndex = rchildIndex;
                }
            }
            else
            {
                break;
            }
        }
    }

    void insert(int data)
    {
        // insert the data in the back of the vector
        pq.push_back(data);

        // check if this data is less than root
        // this is min heap, so data alway be bigger than root
        // up heapify
        int childIndex = pq.size() - 1;
        int rootIndex = ((childIndex)-1) / 2;
        while (childIndex > 0)
        {
            if (pq[childIndex] < pq[rootIndex])
            {
                swap(pq[childIndex], pq[rootIndex]);
                childIndex = rootIndex;
                rootIndex = (childIndex - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }

    void printPq()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};