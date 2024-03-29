#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*int i = 0;
    loop:
     printf("%d ",i);
     i++;
     if(i < 5)
       goto loop;*/
    int i;
    scanf("%d", &i);
    switch (i)
    {
    case 1:
    {
        printf("Dog\n");
        break;
    }
    case 2:
    {
        printf("Rat\n");
        break;
    }
    default:
    {
        printf("Default\n");
    }
    }
    return 0;
}