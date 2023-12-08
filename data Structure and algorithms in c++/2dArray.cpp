#include <iostream>
using namespace std;

// #define FORD(i, start, end) for (i = end; i >= start; i--)

int main()
{
    int mat[10][10];
    int row = 3, col = 3;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    /// Row wise prining
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    /// coloum wise print
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }

    return 1;
}