#include <iostream>
using namespace std;

int fibonacci(int x)
{
    if (x == 1)
    {
        return 1;
    }
    if (x <= 0)
    {
        return 0;
    }
    //
    int smallint1 = fibonacci(x - 1);
    int smallint2 = fibonacci(x - 2);
    return (smallint1 + smallint2);
}
int main()
{
    cout << fibonacci(-1) << endl;
    return 1;
}