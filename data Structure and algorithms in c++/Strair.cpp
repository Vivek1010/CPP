#include <bits/stdc++.h>
using namespace std;

int printWay(int str[], int target)
{
    if (target == str[0])
    {
        return str[0];
    }
    if (target == str[1])
    {
        return str[1];
    }
    if (target == str[2])
    {
        return str[2] + 1;
    }
    return (printWay(str, target - 1) + printWay(str, target - 2) + printWay(str, target - 3));
}

int main()
{
    int str[] = {1, 2, 3};
    cout << printWay(str, 4) << endl;
    return 1;
}
