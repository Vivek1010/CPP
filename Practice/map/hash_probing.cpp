//
// Following program demonstrate the probing technique for
// hash colloition handling.
//
#include <iostream>
#include <vector>
using namespace std;
void rehash(vector<string> &table);

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

int insert(vector<string> &table, string input)
{
    int hash_value = hash_lower_upper_digit(input);
    hash_value %= table.size();
    cout << "table size  " << table.size() << " hash value " << hash_value << endl;
    if (table[hash_value].empty())
    {
        table[hash_value] = input;
    }
    else
    {
        cout << "Hash collision deletected !! Trying probing \n";
        for (int index = hash_value + 1;; index++, index = index % table.size())
        {
            if ((index == hash_value) || (index == hash_value - 1))
            {
                break;
            }
            if (table[index].empty())
            {
                table[index] = input;
                return true;
            }
        }
        cout << "\n Rehash Started  \n";
        rehash(table);
        insert(table, input);
    }
    return 0;
}

string get_random(int len)
{
    string str;
    string alpha[] =
        {
            "abcdefghijklmnopqrstuvwxyz",
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    // 0 or 1
    int pool = rand() % 2;

    for (int i = 0; i < len; i++)
    {
        str += alpha[pool][rand() % 26];
    }
    return str;
}
void rehash(vector<string> &table)
{
    cout << "reshashing started" << endl;
    int old_size = table.size();
    table.resize(old_size * 2);
    vector<string> new_table(old_size * 2);

    for (int i = 0; i < old_size; i++)
    {
        insert(new_table, table[i]);
    }
    table = new_table;
    cout << "reshashing end" << endl;
}
int main(int argc, char *argv[])
{
    int init_size = 0;
    if (argc > 1)
    {
        init_size = atoi(argv[1]);
    }
    else
    {
        cout << "USAGE: ./a.out <int>";
        exit(EXIT_SUCCESS);
    }
    // hash table
    vector<string> table(init_size);
    // table.clear();
    for (string s : table)
    {
        s = "";
    }

    string input;
    cout << "Inital Size of Hash Table " << init_size << endl;
    for (int i = 0; i < 10; i++)
    {
        input = get_random(5);
        (insert(table, input)) ? (cout << "") : (cout << input << " inserted \n");
    }

    exit(EXIT_SUCCESS);
}
