#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        printf("%dth element of arr: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array using bubble sort algorithm
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr); // Don't forget to free the allocated memory
    
    return 0;
}
