#include <stdio.h>
#include <stdlib.h>

void insertarr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void maxarr(int *arr, int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%d is the maximum element of the array.\n", max);
}

void print(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    printf("Enter elements into the array:\n");
    insertarr(arr, n);

    printf("Original array: ");
    print(arr, n);
   
    maxarr(arr, n);

    // Don't forget to free the dynamically allocated memory
    free(arr);

    return 0;
}
