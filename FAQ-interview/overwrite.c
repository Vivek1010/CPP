#include<bits/stdc++.h>

int main(void)
{

    char *b = (char*) malloc(4 * sizeof(char));
    char *c = b;

    std::strcpy(c, "malloc");
    free(b);
    return 0;
}
