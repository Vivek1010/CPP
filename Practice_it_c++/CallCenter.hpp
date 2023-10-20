#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

class CallCenter
{

private:
    queue<double> q;
    double count = 0;

public:
    void receive_call(double &call)
    {
        count++;
        q.push(call);
        cout << "receing call: " << call << endl;
    }

    double process_call()
    {
        if (isEmpty())
        {
            cout << "provessing the call " << q.front() << endl;
            double qfront = q.front();
            q.pop();
            count--;
            return qfront;
        }
        else
        {
            cout << "Nothing to Process" << endl;
        }
        return 0;
    }

    bool isEmpty() { return count; }
};