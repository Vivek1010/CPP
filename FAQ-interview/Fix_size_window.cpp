#include <bits/stdc++.h>
using namespace std;

int max_sum(const vector<int> &nums, const int k)
{
    // calculate the sum
    int sum = 0;
    int max_sum = sum;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
        max_sum = sum;
    }
    int index = k;
    while (index < nums.size())
    {
        sum = sum + nums[index] - nums[index - k];
        cout << "previous sum = " << max_sum << " new sum = " << sum << endl;
        max_sum = max(max_sum, sum);
        index++;
    }
    return max_sum;
}
int main()
{
    vector<int> nums{1, 2, 5, 26, 0, 2, 9, 50, 2, 6};
    int windowSize = 2;

    // find maximum sum of window size 3
    cout << max_sum(nums, windowSize);
    return 1;
}