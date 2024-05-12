//
// write a hash function a string
// lower case, upper case and digit
//

#include <iostream>
using namespace std;

int hash_lower_upper_digit(string input, int n = 65554)
{
    long long sum = 0;
    int base = (2 * 26) + 10; // lower + uppper+ digit
    int char_value = 0;
    for (char c : input)
    {
        if (islower(c))
        {
            char_value = c - 'a';
        }
        else if (isupper(c))
        {
            char_value = c - 'A' + 26;
        }
        else
        {
            char_value = c - '0' + (26 * 2);
        }
        sum = (sum * base) + char_value;
        sum %= n;
    }
    return sum;
}

int hash_folding_string(string input, int block_size = 4)
{
    int n = 65554;
    long long sum = 0;
    for (int i = 0; i < input.length(); i += 4)
    {
        string sub_string = input.substr(i, block_size);
        sum += hash_lower_upper_digit(sub_string);
    }
    return sum %= n;
}
int main()
{
    cout << hash_lower_upper_digit("vivek") << endl;
    cout << hash_lower_upper_digit("ivvke") << endl;
    cout << hash_lower_upper_digit("b") << endl;
    cout << hash_folding_string("asdfghjk") << endl;
    cout << hash_folding_string("1243284089264") << endl;
    cout << hash_folding_string("ASHKJGSFOIUJSGFJGJG") << endl;
    return 0;
}