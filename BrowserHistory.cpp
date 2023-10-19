#include "BrowserHistory.hpp"
int main()
{
    string input[] = {"www.google.com", "www.amazon.com", "www.flipcart.com", "www.xyz.com"};
    BrowserHistory bh;
    bh.visit(input[0]);
    cout << bh.current() << endl;
    bh.visit(input[1]);
    cout << bh.current() << endl;
    bh.back();
    cout << bh.current() << endl;
    return 1;
}