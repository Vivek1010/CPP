#include "truecaller.h"
int main()
{
    //{"9632419312", "Ann"}
    unordered_map<string, string> contacts = {
        {"9632726699", "Vivek"}, {"9632419312", "Ann"},
        {"9632419208", "Bhabhi"}, {"9632628601", "Pussu"}
        };

    truecaller t;
    for (auto it : contacts)
    {
        auto status = t.insert(it.first, it.second);
        if (!status)
        {
            cout << it.second << " is not inserted  " << endl;
        }
        //cout << it.second << " inserted  sucessfully" << endl;
    }
    cout << "Seraching 9632419312 >>> "
         <<  t.search("9632419312") << endl;
    cout << "Seraching 9632726699  >>> "
         <<  t.search("9632726699") << endl;
    return 1;
}

bool truecaller::insert(string phNumber, string name_terminal)
{
    Node *temp = root;
    for (int idx = 0; idx < phNumber.size(); idx++)
    {
        char data = phNumber[idx];
        int index = data - '0';
        if (temp->child[index] == nullptr)
        {
            temp->child[index] = new Node();
        }
        temp = temp->child[index];
    }
    temp->isTerminal = true;
    temp->name = name_terminal;
    return true;
}

string truecaller::search(string phNumber)
{
    Node *temp = root;
    for (int idx = 0; idx < phNumber.size(); idx++)
    {
        int index = phNumber[idx] - '0';
        
        if(temp->child[index] == nullptr)
        {
            cout << index << " Not found" << endl;
            return nullptr;
        }
        temp = temp->child[index];
    }
    if(temp->isTerminal)
    {
        return temp->name;
    }
    cout << " not Found " << endl;
    return nullptr;
}