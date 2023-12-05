#include <bits/stdc++.h>
using namespace std;

int TohNumberOfSteps(int disks)
{
    if (disks == 0)
    {
        return 0;
    }
    /// steps tp put (N-1) disck to Temp tower
    /// + 1 step to put biggest disk in final tower
    /// + steps tp put (N-1) disks to final tower
    return (TohNumberOfSteps(disks - 1) + 1 + TohNumberOfSteps(disks - 1));
}

void PrintSteps(int disks, char source, char destination, char helper)
{
    if (disks == 0)
    {
        return;
    }
    PrintSteps(disks - 1, 'A', 'B', 'C');
    cout << "Moving disk " << disks << " from " << source << " to " << destination << endl;
    PrintSteps(disks - 1, 'B', 'C', 'A');
}

int main()
{
    cout << TohNumberOfSteps(1) << endl;
    cout << TohNumberOfSteps(2) << endl;
    cout << TohNumberOfSteps(3) << endl;
    cout << TohNumberOfSteps(4) << endl;
    PrintSteps(3, 'A', 'C', 'B');
    return 1;
}
