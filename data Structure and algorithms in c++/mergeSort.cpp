#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int s1, int e1, int s2, int e2)
{
    int leftArraySize = e1 - s1;
    int rightArraySize = e2 - s2;
    int leftarray[leftArraySize];
    int rightarray[rightArraySize];
    cout << leftArraySize << " " << leftArraySize << endl;
    // copy left and right
    for (int i = 0; i <= leftArraySize; i++)
    {
        leftarray[i] = nums[s1 + i];
    }
    for (int j = 0; j <= rightArraySize; j++)
    {
        rightarray[j] = nums[s2 + j];
    }
    int index = s1;
    while (s1 <= e1 && s2 <= e2)
    {
        if (leftarray[s1] < rightarray[s2])
        {
            nums[index] = leftarray[s1];
            s1++;
            leftArraySize--;
        }
        else
        {
            nums[index] = rightarray[s2];
            s2++;
            rightArraySize--;
        }
        index++;
        if (leftArraySize == 0)
        {
            for (int i = 0; i < rightArraySize; i++)
            {
                nums[index] = rightarray[s2];
                s2++;
                index++;
            }
            break;
        }
        if (rightArraySize == 0)
        {
            for (int i = 0; i < leftArraySize; i++)
            {
                nums[index] = leftarray[s1];
                s1++;
                index++;
            }
            break;
        }
    }
}
void mergeSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    cout << "mid " << mid << " ";
    mergeSort(nums, s, mid); 
    mergeSort(nums, mid + 1, e);
    merge(nums, s, mid, mid + 1, e);
}
vector<int> sortArray(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    mergeSort(nums, s, e);
    return nums;
}

int main()
{
    vector<int> nums{3,5,1,6,7};
    vector<int> res = sortArray(nums);
    for(int i = 0; i< res.size();i++)
    {
        cout<< res[i] << " ";
    }
    return 1;
}