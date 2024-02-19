#include <bits/stdc++.h>
using namespace std;

void brute_force(vector<int> arr, int target)
{
    int size = arr.size();
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << "got the answer " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
}

void pointer_with_bf(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int low = 1, high = arr.size() - 1;
        int left_target = target - arr[i];
        while (low < high)
        {
            if (arr[low] + arr[high] == left_target)
            {
                cout << "got the answer " << arr[i] << " " << arr[low] << " " << arr[high] << endl;
                return;
            }
            else if (arr[low] + arr[high] > left_target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
    }
}

int main()
{
    vector<int> arr{2, 4, 7, 8, 13, 15, 17, 19, 20, 21, 22, 23, 24, 250};
    int target = 256;

    // O(N3)
    brute_force(arr, target);

    // O(N2)
    pointer_with_bf(arr, target);

    return 1;
}