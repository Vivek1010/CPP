#include "Anamaly.hpp"

int main()
{
    anamaly adata;
    int data_limit = 100;
    
    while (data_limit--)
    {
        srand(time(NULL) + data_limit);
        auto data = rand() % 100000;
        adata.add_reading(data);
    }
    int x;
    adata.add_reading(x = 1);
    adata.print_data();
    adata.smooth_data();
    adata.print_data();
    return 0;
}
