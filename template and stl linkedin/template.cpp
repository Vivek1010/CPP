#include <bits/stdc++.h>
using namespace std;

template <typename T>
T maxof(const T &a, const T &b)
{
    return (a > b ? a : b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << (a + b) << endl;
    // cout << "----------" << endl;
    // cout << maxof<int>(700, 90000) << endl;
    return 1;
}