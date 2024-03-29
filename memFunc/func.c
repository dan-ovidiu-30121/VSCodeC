#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int arr1[] = {3,4};
    int arr2[] = {1,2};
    /*if(memcmp(arr1,arr2,2*sizeof(short int))==0){
        printf("Arrays are the same\n");
    }
    else
    {
        printf("Arrays are not the same\n");
    }*/
    /*memcpy(arr1,arr2,2*sizeof(int));
    printf("%d %d\n",arr1[0],arr1[1]);*/
    /*memset(arr1,0,2*sizeof(int));
    printf("%d %d\n",arr1[0],arr1[1]);*/
    memchr(arr1,0,2*sizeof(int));
    return 0;
}