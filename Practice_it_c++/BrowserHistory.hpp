#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory
{
public:
    void
    visit(const string &url)
    {
        history.push(url);
        count++;
    }
    void
    back()
    {
        if (count)
            history.pop();
        else
            cout << "No History" << endl;
    }
    string current() const
    {
        return history.top();
    }
    bool isEmpty(){return count;};

private:
    stack<string> history;
    int count = 0;
};