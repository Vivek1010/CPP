#include <iostream>
using namespace std;

template <typename T>
int search(const T inputArr[], size_t size, T tar)
{
    for (int i = 0; i < size; ++i)
    {
        if (inputArr[i] == tar)
            return i;
    }
    return -1;
}

int main()
{
    float inputArr[] = {1, 3, 45, 245.1, 235, 4567, 35, 36, 456, 2345, 658, 84, 42, 456};
    cout << "index = " << search(inputArr, (sizeof(inputArr) / sizeof(float)), (float)245.1) << endl;
    return 1;
}