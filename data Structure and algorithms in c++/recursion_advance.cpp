#include <bits/stdc++.h>
using namespace std;

void printArray(char *str)
{
    if (str[0] == '\0')
    {
        return;
    }
    cout << str[0];
    printArray(str + 1);
}
void printRev(char str[], int len)
{
    if (len == 0)
    {
        return;
    }
    cout << str[len - 1];
    printRev(str, len - 1);
}
void printRev2(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    printRev2(str + 1);
    cout << str[0];
}
int findLen(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return (1 + findLen(str + 1));
}
void replaceChar(char str[], char target, char replace)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == target)
    {
        str[0] = replace;
    }
    replaceChar(str + 1, target, replace);
}
void removeChar(char str[], char target, char ans[], int index)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] != target)
    {
        ans[index] = str[0];
        removeChar(str + 1, target, ans, index + 1);
    }
    else
    {
        removeChar(str + 1, target, ans, index);
    }
}
void removeConse(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == str[1])
    {
        int i = 0;
        while (str[i] != '\n')
        {
            str[i] = str[i + 1];
            i++;
        }
        removeConse(str);
    }
    else
    {
        removeConse(str + 1);
    }
}

int main()
{
    char str[] = "abcefghijklmno";
    cout << "original String = ";
    printArray(str);
    cout << endl
         << "Reversed String = ";
    printRev2(str);
    cout << endl;

    char str2[] = "123456";
    cout << "length of str2  = " << findLen(str2);
    cout << endl;
    cout << "original String = ";
    printArray(str2);
    cout << endl;
    cout << "Modified String = ";
    replaceChar(str2, '1', '9');
    cout << str2;
    cout << endl;

    char str3[] = "abc1def";
    char ans[sizeof(str3)];
    cout << "original String = ";
    cout << str3;
    cout << endl;
    removeChar(str3, '1', ans, 0);
    cout << "Modified String = ";
    cout << ans;

    cout << endl;
    char str4[] = "aaaaabbbbbbcccccc1111112222222222dddddeeeeefffffff";
    cout << "original String = ";
    cout << str4;
    removeConse(str4);
    cout << endl;
    cout << "Modified String = ";
    cout << str4;
    cout << endl;
    return 1;
}