#include <bits/stdc++.h>
using namespace std;

void brute_force(vector<int> arr, int target)
{
    int size = arr.size();
    for (int i = 0; i < size - 3; i++)
    {
        for (int j = i + 1; j < size - 2; j++)
        {
            for (int k = j + 1; k < size - 1; k++)
            {
                for (int l = k + 1; k < size; k++)
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                    {
                        cout << "got the answer " << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << endl;
                    }
            }
        }
    }
}

void build_table(unordered_map<int, pair<int, int>> &table, vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            table[arr[i] + arr[j]] = {arr[i], arr[j]};
            cout << " building ... " << arr[i] + arr[j] << endl;
        }
    }
}
void ht_search(vector<int> arr, int target)
{
    unordered_map<int, pair<int, int>> table;
    build_table(table, arr);
    cout << target << endl;
    for (auto it : table)
    {
        if (table.count(target - it.first) )
        {
            cout << it.second.first << " " << it.second.second << " " << table[target - it.first].first << " " << table[target - it.first].second << endl;
        }
        cout << "searching  pair " << it.first << " " << target - it.first << endl;
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 6 + 7 + 8 + 9;

    // O(N3)
    // brute_force(arr, target);

    // Hash table search
    ht_search(arr, target);

    return 1;
}