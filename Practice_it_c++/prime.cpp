/*
 * from Given array of integers, prints the prim number
 */
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void findPrim(int input[], size_t size, vector<int> &vec)
{
    for (int i = 0; i < size; i++)
    {
        if (isPrime(input[i]))
        {
            vec.push_back(input[i]);
        }
    }
}
int main()
{
    // cout << "in main" << endl;
    int input[] = {1, 2, 334, 23, 35, 7, 34, 234, 865, 3456, 9873, 5629, 43567,1, 2};
    vector<int> vec{};
    findPrim(input, (sizeof(input) / sizeof(int)), vec);
    cout << "prime no are : " << endl;
    for (int inputPrint : vec)
    {
        cout << inputPrint << " ";
    }
    cout << endl;
    return 1;
}