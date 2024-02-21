#include <iostream>
void func(int x)
{
    std::cout << x << "\n";
    func(x + 1);
}

int main()
{
    func(1);
    return 1;
}