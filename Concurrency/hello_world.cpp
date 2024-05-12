#include <iostream>
#include <thread>
using namespace std;

// void threadFunction()
// {
//     cout << "from the thread \n";
// }
int main()
{
    thread th([]()
              { cout << "from the thread \n"; });

    cout << "from the main \n";
    th.join();

    return 0;
}