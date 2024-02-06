#include "Vector.h"
int main()
{
    Vector *v = new Vector();
    for (int i = 0; i < 20; i++)
    {
        v->push_back(i);
    }
    cout << v->front();
    cout << v->back();
    cout << v->at(15);
    delete v;
    return 1;
}

void Vector::push_back(int entry)
{
    if (getIndex() == _capacity)
    {
        cout << "allocating more " << endl;
        allocate_more();
    }
    add(entry);
}

int Vector::front()
{
    return arr[0];
}

int Vector::back()
{
    return arr[getIndex() - 1];
}