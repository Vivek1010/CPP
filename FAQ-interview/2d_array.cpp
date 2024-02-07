#include<iostream>
using namespace std;

void printArr(int* arr[],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        cout << "ROW " << i << ": ";
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    int m,n;
    //m row and n coloums
    cout << " Enter the value of Row and col " << endl;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i <n; i++)
    {
        arr[i] = new int[n];
    }
    printArr(arr,m,n);
    for (int i = 0; i < n; i++)
    {
        delete []arr[i];
    }
    delete [] arr;
    return 1;  
}