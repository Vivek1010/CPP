#include<iostream>
using namespace std;

class instrument
{
    public:
    virtual void makeSound()
    {
        cout << "Instrument playing ...\n";
    }
    virtual void repair() = 0;
};

class piano : public instrument
{
    public:
        void makeSound()
        {
            cout << "Piano playing ...\n";
        }
        void repair()
        {
            cout << "Repairing piano ...\n";
        }
};

int main()
{
    instrument *i1 = new piano();
    i1->makeSound();
    i1->repair();
    return 1;
}