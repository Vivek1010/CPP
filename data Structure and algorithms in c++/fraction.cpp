#include "fraction.h"

int main()
{
    fraction f1(1, 2);
    fraction f2(1, 2);
    // f1.add(f2);
    //  f1.printF();

    fraction f3(0, 0);
    f3 = f1 * f2;
    f3.printF();

    fraction f4(1, 4);
    string rv;
    cout << (rv = (f3 == f4) ? "they are equal" : "not qual") << endl;
    // cout << rv << endl;

    fraction f6 = ++f4;
    f6.printF();
    return 1;
}