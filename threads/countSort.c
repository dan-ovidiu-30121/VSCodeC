#include <stdio.h>
#include <stdlib.h>

int* countSort(int *arr, int n) {
    int max = -10000000;
    for (int i = 0; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    
    int *countArray = (int *)calloc(max + 1, sizeof(int));
    int *outputArray = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        countArray[arr[i]]++;
    
    for (int i = 1; i <= max; i++)
        countArray[i] += countArray[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    
    free(countArray);
    return outputArray;
}

int findMedian(int n, int *arr) {
    int *res = countSort(arr, n);
    return res[n / 2];
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", findMedian(n, arr));
    
    free(arr);
    return 0;
}
