#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr1[] = {1, 2};
    int arr2[] = {2, 1};
    int n = 2; // size of the arrays

    // Dynamically allocate memory for arr3
    int *arr3 = (int *)malloc(n * sizeof(int));

    if (arr3 == NULL) {
        printf("Memory allocation failed\n");
        return 1; // indicate failure
    }

    int count = 0; // to keep track of the number of elements in the intersection

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[count++] = arr1[i];
                break; // exit the inner loop since we found a match
            }
        }
    }

    printf("Intersection of two arrays: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr3[i]);
    }

    // Don't forget to free the dynamically allocated memory
    free(arr3);

    return 0;
}
