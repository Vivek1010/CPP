#include <iostream>
using namespace std;

void print_reverse(char *s)
{
    if (*s == '\0')
    {
        return;
    }
    print_reverse(s + 1);
    cout << *s;
}
int main()
{
    char s1[] = "abcdefghi";
    char *s2 = "ABCDE"
    print_reverse(s1);
    reverse(s1);
    return 1;
}