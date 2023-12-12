#include <bits/stdc++.h>
using namespace std;

void printVec(vector<vector<int>> const &v)
{
    int row = v.size();
    int colum = v[1].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void spiralPrint(vector<vector<int>> const &v)
{
    if (v.size() == 0)
    {
        return;
    }
    int sr = 0;
    int er = v.size() - 1;
    int sc = 0;
    int ec = v[1].size() - 1;
    int count = 0;
    int total = (er + 1) * (ec + 1);
    // cout << "count " << count << " er " << er << " ec " << ec << " st " << sr << " sc " << sc << endl;
    while ((sr <= er) || (sc <= ec))
    {
        // step 1: print row
        for (int i = sc; i <= ec; i++)
        {
            cout << v[sr][i] << " ";
            count++;
        }
        if (count >= total)
        {
            return;
        }
        cout << endl;
        sr++;
        // cout << "count " << count << " er " << er << " ec " << ec << " st " << sr << " sc " << sc << endl;
        // step - 2 print the colum
        for (int i = sr; i <= er; i++)
        {
            // cout << sr << " " << ec << " ->";
            cout << v[i][ec] << " ";
            count++;
        }
        ec--;
        if (count >= total)
        {
            return;
        }
        cout << endl;
        // cout << "count " << count << " er " << er << " ec " << ec << " st " << sr << " sc " << sc << endl;
        //  step-3 print lowest row
        for (int i = ec; i >= sc; i--)
        {
            cout << v[er][i] << " ";
            count++;
        }
        cout << endl;
        er--;
        if (count >= total)
        {
            return;
        }
        // cout << "count " << count << " er " << er << " ec " << ec << " st " << sr << " sc " << sc << endl;
        //  step-4 print first colum down to up
        for (int i = er; i >= sr; i--)
        {
            cout << v[i][sc] << " ";
            count++;
        }
        er--;
        if (count >= total)
        {
            return;
        }
        cout << endl;
        // cout << "count " << count << " er " << er << " ec " << ec << " st " << sr << " sc " << sc << endl;
    }
}
int main()
{
    vector<vector<int>> v = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    // printVec(v);
    spiralPrint(v);
    return 1;
}