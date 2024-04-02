
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int auth = 0;
    char buf[10];
    cout << "enter the pass" <<endl;
    cin >>buf;
    if(std::strcmp(buf,"pass",10))
    {
       auth = 1;     
    }
    if (auth)
    {
        cout << "corrent pass" <<endl;
    } 
    else
    {
        cout << "wrong pass" <<endl;
    }
    return 1;
}

