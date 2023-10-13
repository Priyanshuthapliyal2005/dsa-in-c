#include <stdio.h>

int main() {
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    int arr3[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            arr3[i] = arr1[i];
        } else {
            arr3[i] = arr2[i - 2];
        }
    }

    // Print the union of the two arrays
    printf("Union of two arrays: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}
