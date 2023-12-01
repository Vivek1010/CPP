#include <iostream>
using namespace std;

double power(int base, int race)
{
    if (race <= 1)
    {
        return base;
    }
    // odd
    if (race & 1)
    {
        return (power(base, (race / 2) + 1) * power(base, race / 2));
    }
    // even
    else
    {
        return (power(base, (race / 2)) * power(base, race / 2));
    }
}

void printNumber(int x)
{
    if (x == 0)
    {
        return;
    }

    printNumber(x - 1);
    cout << x << " ";
}

int count(int number)
{
    if (number == 0)
    {
        return 0;
    }
    return (1 + count(number / 10));
}

int add(int number)
{
    if (number < 10)
    {
        return number;
    }
    return (number % 10 + add(number / 10));
}
int multiplication(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    // int smallans = multiplication(m, n - 1);
    return (m + multiplication(m, n - 1));
}

int countZero(int number)
{
    if (number == 0)
    {
        return 0;
    }
    if (number % 10 == 0)
    {
        return (countZero(number / 10) + 1);
    }
    else
    {
        return countZero(number / 10);
    }
}

float Gsum(int number, int pwr)
{
    if (pwr == 0)
    {
        return 1;
    }
    float smallans = Gsum(number, pwr - 1);
    return (smallans + 1.0 / power(number, pwr));
}
int main()
{
    // cout << power(2, 0);
    // printNumber(25);
    // cout << count(123456789);
    // cout << add(123456);
    // cout << multiplication(4, 15);
    // cout << countZero(100000);
    cout << Gsum(2, 8);
    return 1;
}