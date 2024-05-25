#include <iostream>
#include <mutex>
using namespace std;

class singleton
{
private:
    singleton()
    {
        cout << "instance created\n"
             << endl;
    }
    ~singleton() {}
    static mutex mtx;
    static singleton *inst;

public:
    static singleton *getinstace()
    {
        //
        // Double locking
        // first check for instance and
        // second if we are required to use mutex
        //
        if (inst == nullptr)
        {
            singleton::mtx.lock();
            if (inst == nullptr)
            {
                inst = new singleton();
            }
            singleton::mtx.unlock();
        }
        return inst;
    }
    void print(string msg)
    {
        cout << "Printing " << msg << endl;
    }
};
