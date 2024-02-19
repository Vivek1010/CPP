#include<iostream>
using namespace std;

int setbit(int &n, int pos)
{
    n = (n | 1 << pos);
    return (n);
}

int unSetbit(int n, int pos)
{
    n = (n & ~(1 << pos));
    return (n);
}
int getBit(int n, int pos)
{
    bool res;
    return (res = n & (1<<pos) ? 1 : 0);
}
int UpdateBit(int n, int pos, bool val)
{
    // clear bit
    n = n & ~(1<<pos);
    n = n | (val<<pos);
    return n;
}

int main()
{
    int n = 00;

    cout << setbit(n, 8) << endl;
    cout << setbit(n, 7) << endl;
    cout << unSetbit(n, 7) << endl;
    cout << getBit(n, 8) << endl;
    cout << UpdateBit(n, 8, 1) << endl;
    cout << UpdateBit(n, 8, 0) << endl;
    return 1;
}