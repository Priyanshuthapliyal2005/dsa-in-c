#include <stdio.h>
#include <stdlib.h>

void insertarr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void revarr(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

void printarr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // indicate failure
    }

    // Insert elements into the array
    printf("Enter elements into the array:\n");
    insertarr(arr, n);

    // Print the original array
    printf("Original array: ");
    printarr(arr, n);

    // Reverse the array
    revarr(arr, n);

    // Print the reversed array
    printf("Reversed array: ");
    printarr(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
