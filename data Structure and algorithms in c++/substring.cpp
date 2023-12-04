#include <bits/stdc++.h>
using namespace std;

void substringPrint(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    substringPrint(str.substr(1), output);
    substringPrint(str.substr(1), output + str[0]);
}
void substringPrint2(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    substringPrint2(str.substr(1), output);
    substringPrint2(str.substr(1), output + str[0]);
}
void substringStore(string str, string output, string &ans)
{
    if (str.length() == 0)
    {
        ans += " ";
        ans += output;
        return;
    }

    substringStore(str.substr(1), output, ans);
    substringStore(str.substr(1), output + str[0], ans);
}

double power(int base, int race)
{
    if (race == 0)
    {
        return 1;
    }
    if (race == 1)
    {
        return base;
    }
    if (race & 1)
    {
        return (power(base, race / 2) * power(base, (race / 2 + 1)));
    }
    else
    {
        return (power(base, race / 2) * power(base, (race / 2)));
    }
}

double convertStringToInt(string input, int len, int index)
{
    if (len == 0)
    {
        return 0;
    }
    double smallAns = (input[len - 1] - '0') * power(10, index);
    return (smallAns + convertStringToInt(input, len - 1, index + 1));
}

double convertStringToInt2(string input, int len)
{
    if (len == 0)
    {
        return 0;
    }
    return (convertStringToInt2(input, len - 1) * 10 + input[len - 1] - '0');
}

void printPermute(char str[], int index = 0)
{
    if (str[index] == '\0')
    {
        cout << str << " ";
        return;
    }
    for (int rest = index; str[rest] != '\0'; rest++)
    {
        swap(str[index], str[rest]);
        printPermute(str, index + 1);
        swap(str[rest], str[index]);
    }
}

int main()
{
    string str{"abc"};
    cout << "-----------" << endl;
    string output;
    substringPrint(str, output);
    cout << "-----------" << endl;
    substringPrint2(str, output);
    string ans;
    substringStore(str, output, ans);
    cout << "-----------" << endl;
    cout << ans << endl;

    cout << "-----------" << endl;
    string str5 = "1265523452295";
    cout << convertStringToInt(str5, str5.length(), 0) << endl;
    cout << "-----------" << endl;

    cout << "-----------" << endl;
    string str6 = "9795";
    cout << convertStringToInt2(str6, str6.length()) << endl;
    cout << "-----------" << endl;

    cout << "-----------" << endl;
    char str7[] = "ABC";
    printPermute(str7);
    cout << "-----------" << endl;
    return 1;
}