#include <bits/stdc++.h>
using namespace std;

int max_diff(const vector<int> &nums)
{
    int ans = INT_MIN;
    int min_so_far = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans = max(ans, nums[i] - min_so_far);
        // upcoming value is lower
        if (nums[i] < min_so_far)
        { 
            min_so_far = nums[i];
        }
       
    }
    return ans;
}
int main()
{
    vector<int> nums{1000, 2, 3, 10, 7, 99};
    cout << max_diff(nums);
    return 1;
}