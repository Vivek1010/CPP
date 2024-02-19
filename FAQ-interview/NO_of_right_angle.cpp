#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int countTriangle(const vector<vector<int>> &arr)
{
    // X(axis) -> Y(cordinates);
    unordered_map<int, unordered_set<int>> m;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];
        m[x] = m[x].insert(y);
    }
    // Now search the cordinates in the map
    // Need to brute force here with 2 points
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            int x2 = arr[j][0];
            int y2 = arr[j][1];

            if (x1 == x2 || y1 == y2)
            {
                continue;
            }
            if ()
        }
    }
}

int main()
{
    // input
    vector<vector<int>> arr{{1, 1}, {1, 4}, {4, 1}.{4, 4}};
    cout << " no of right angle triangle = " << countTriangle(arr);
    return 1;
}