#include <stdio.h>
#include <string.h>

int main(void)
{

    char buff[4];
    int authentication = 0;

    printf("\n Enter the password : \n");
    scanf("%s", buff);

    if (strncmp(buff, "pass", 4) == 0)
    {
        authentication = 1;
    }
    if (authentication)
    {
        printf("\n Password is correct\n");
    }
    else
    {
        printf("\n Wrong password provided\n");
    }
    printf(" size =  %d", sizeof(int *));
    return 0;
}
