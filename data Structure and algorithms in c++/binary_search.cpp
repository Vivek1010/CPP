#include <bits/stdc++.h>
using namespace std;

int helper_recursive(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    // cout << mid << endl;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (target < nums[mid])
    {
        return helper_recursive(nums, start, mid-1, target);
    }
    else
    {
        return helper_recursive(nums, mid + 1, end, target);
    }
}
int searchBs(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1; // last valid index
    if (target < nums[0] || target > nums[nums.size() - 1])
    {
        return -1;
    }
    return helper_recursive(nums, start, end, target);
}

int main()
{
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << searchBs(nums, target);
    return 1;
}