#include "bits/stdc++.h"
using namespace std;

void rec_arr(int arr[], int left, int right)
{
    if (left >= right)
        return;
    swap(arr[left], arr[right]);
    rec_arr(arr, left + 1, right - 1);
}
template <typename T>
void msg(const char *s, const T &v = 0)
{
    cout << s << " " << v << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]{2, 4, 6, 1, 6, 7};
    msg("original array", 0);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    rec_arr(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}