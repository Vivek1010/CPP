#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

//
// Unique substring count
//
int get_substring_count(string &s)
{
    string sub;
    int i = 0,
        j = 0;
    unordered_set<string> set_s;
    set_s.clear();
    for (i = 0; i < s.size(); i++)
    {
        for (j = i; j < s.size(); j++)
        {
            (i == j) ? (sub = s[i]) : (sub += s[j]);
            // sub = s.substr(i, j+1);
            // cout << "inserting1 " << sub << endl;

            // cout << "inserting1 " << sub << endl;
            set_s.insert(sub);
        }
        sub.clear();
    }
    return set_s.size();
}
int main()
{
    vector<string> input = {
        "aaab",
        "aaaaa",
        "aaaba",
        "abcdef"};
    for (int i = 0; i < input.size(); i++)
    {
        cout << endl
             << get_substring_count(input[i]) << endl;
    }
    exit(EXIT_SUCCESS);
}