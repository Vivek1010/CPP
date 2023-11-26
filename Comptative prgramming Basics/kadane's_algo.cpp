#include "bits/stdc++.h"
using namespace std;

#if 0

template <typename T>
void msg(const char *s, const T &v = 0)
{
    cout << s << " " << v << '\n';
}

#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Kadane's Algo
    int curr_sum = a[0], max_sum_sofar = a[0];
    for (int i = 1; i < n; i++)
    {
        curr_sum = max(a[i], curr_sum + a[i]);
        max_sum_sofar = max(max_sum_sofar, curr_sum);
        // return max_sum_sofar;
    }
    cout << " max sum >> " << max_sum_sofar;
    return 1;
}