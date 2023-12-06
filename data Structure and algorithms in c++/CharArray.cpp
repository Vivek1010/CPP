#include <bits/stdc++.h>
using namespace std;

int length(char target[])
{
    int i = 0;
    while (target[i] != '\0')
    {
        i++;
    }
    return i;
}

/// @brief recursive strcmp function
/// @param str1
/// @param str2
/// @return true or flase
bool str_cmp(char str1[], char str2[])
{
    if (str1[0] == '\0')
    {
        return true;
    }
    if (str1[0] != str2[0])
    {
        return false;
    }
    return (str_cmp(str1 + 1, str2 + 1));
}

void printSuffx(char input[])
{
    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        for (int j = i; j < strlen(input); j++)
        {
            cout << input[j];
        }
        cout << endl;
    }
}
int main()
{

    /*
      char name[10000];
      cin.getline(name, 20);
      name[3] = 'x';
      name[4] = 'y';
     */
    int i = 0;
#if 0
    while (name[i++] != 'z')
    {
        cout << name[i];
        if (i % 4 == 0)
        {
            cout << " ";
        }
        if (i % 16 == 0)
        {
            cout << "\n";
        }
    }
#endif
    // cout << length(name) << endl;
    char s1[100], s2[100];
    cout << "enter the first string \n";
    cin.getline(s1, 20);
    cout << "enter the second string \n";
    cin.getline(s2, 20);
    // bool rv = str_cmp(s1, s2) ? cout << " string are equal" : cout << "string are not equal";
    if (str_cmp(s1, s2))
    {
        cout << " string are equal \n";
    }
    else
    {
        cout << "string are not equal \n";
    }
    printSuffx(s1);
    return 1;
}
