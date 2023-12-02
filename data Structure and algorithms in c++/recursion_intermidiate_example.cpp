#include <bits/stdc++.h>
using namespace std;

bool isSorted_arr(int arr[], int end)
{
    if (end == 0)
    {
        return true;
    }
    bool smallans1 = isSorted_arr(arr, end - 1);
    bool smallans2 = arr[end] >= arr[end - 1] ? true : false;
    return (smallans1 && smallans2);
}
/// @brief comparing from 0 to end index
/// @param arr
/// @param end
/// @return
bool isSorted2(int arr[], int end)
{
    if (end == 0)
    {
        return true;
    }
    bool smallans1 = arr[0] <= arr[1] ? true : false;
    bool smallans2 = isSorted2(arr + 1, end - 1);
    return (smallans1 && smallans2);
}
/// @brief comparing from last index to zero index.
/// @param arr
/// @param size
/// @return
bool isSorted(int arr[], int size)
{
    // return isSorted_arr(arr, size - 1);
    return isSorted2(arr, size - 1);
}

int sumArry(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }
    return (arr[size - 1] + sumArry(arr, size - 1));
}

bool isPresent(int arr[], int size, int target)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[size - 1] == target)
    {
        return true;
    }
    return isPresent(arr, size - 1, target);
}

int firstIndex(int arr[], int size, int target, int index)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return (firstIndex(arr, size, target, index + 1));
}

int lastIndex(int arr[], int size, int target, int index)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == target)
    {
        return (size - 1);
    }
    return (lastIndex(arr, size - 1, target, 0));
}

void printAllPosition(int arr[], int size, int target)
{
    if (size == 0)
    {
        return;
    }
    if (arr[size - 1] == target)
    {
        cout << size - 1 << " ";
    }
    return (printAllPosition(arr, size - 1, target));
}

int CountFq(int arr[], int size, int target, int count)
{
    if (size == 0)
    {
        return count;
    }
    if (arr[size - 1] == target)
    {
        count++;
    }
    return (CountFq(arr, size - 1, target, count));
}

int CountFq2(int arr[], int size, int target)
{
    if (size == 0)
    {
        return 0;
    }
    if (arr[0] == target)
    {
        return (1 + CountFq2(arr + 1, size - 1, target));
    }
    else
    {
        return (0 + CountFq2(arr + 1, size - 1, target));
    }
}

void saveAllPositionInArry(int arr[], int size, int target, int output[], int position)
{
    if (size == 0)
    {
        return;
    }
    if (arr[size - 1] == target)
    {
        output[position] = size - 1;
        saveAllPositionInArry(arr, size - 1, target, output, position + 1);
    }
    else
    {
        saveAllPositionInArry(arr, size - 1, target, output, position);
    }
}
void saveAllPositionInArry2(int arr[], int size, int target, vector<int> &ans)
{
    if (size == 0)
    {
        return;
    }
    if (arr[size - 1] == target)
    {
        ans.push_back(size - 1);
        saveAllPositionInArry2(arr, size - 1, target, ans);
    }
    else
    {
        saveAllPositionInArry2(arr, size - 1, target, ans);
    }
}

bool ArrayPallendrom(int arr[], int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (arr[start] != arr[end])
    {
        return false;
    }
    return ArrayPallendrom(arr, start + 1, end - 1);
}

int main()
{
    int arr[]{1, 2, 2, 10, 5, 5, 5, 5, 5, 5, 1220, 10};
    int out[]{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int arr2[]{1, 2, 3, 3, 2, 1};

    vector<int> ans;

    cout << "isSorted   " << isSorted(arr, sizeof(arr) / sizeof(arr[1])) << endl;
    cout << "Array Sum  " << sumArry(arr, (sizeof(arr) / sizeof(arr[1]))) << endl;
    // cout << isPresent(arr, 6, 1220);
    cout << "first index " << firstIndex(arr, (sizeof(arr) / sizeof(arr[1])), 5, 0) << endl;
    cout << "lastINdex " << lastIndex(arr, (sizeof(arr) / sizeof(arr[1])), 5, 0) << endl;
    printAllPosition(arr, (sizeof(arr) / sizeof(arr[1])), 5);
    cout << endl
         << "count " << CountFq(arr, (sizeof(arr) / sizeof(arr[1])), 5, 0);
    cout << endl
         << "count2 " << CountFq2(arr, (sizeof(arr) / sizeof(arr[1])), 10) << endl;

    saveAllPositionInArry(arr, (sizeof(arr) / sizeof(arr[1])), 5, out, 0);

    for (int i = 0; i < 10; i++)
    {
        if (out[i] != -1)
        {
            cout << out[i] << " ";
        }
    }
    cout << endl;
    saveAllPositionInArry2(arr, (sizeof(arr) / sizeof(arr[1])), 5, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << "ArrayPallendrom  = " << ArrayPallendrom(arr2, 0, (sizeof(arr2) / sizeof(arr2[1])) - 1);
    return 1;
}