#include <iostream>
using namespace std;

struct foo3
{
    char *p;  /* 8 bytes */
    char c;   /* 1 byte */
    //pad[7]; /* 7 byte */
};

struct foo10
{
    //long y;
    //struct foo10 *p;   /* 8 */
    int c;  
    char cc;
    int ic;          /* 1 + 3 padding */
    //short x;           /* 2*/
    int x;
    
};

int main()
{
    struct foo3 singleton;
    struct foo3 quad[4];
    cout << "sizeof singleton " << sizeof(singleton) << endl;
    cout << "sizeof quad " << sizeof(quad) << endl;

    cout << "sizeof foo10 " << sizeof(foo10) << endl;
    return 1;
}