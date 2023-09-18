#include<stdio.h>
#include<stdlib.h>

float area(int **r) {
    *r = (int*)malloc(sizeof(int));
    printf("enetr the radius: ");
    scanf("%d", *r);
    float a = 3.14 * (**r) * (**r);
    return a;
}

float peri(int *r) {
    float p = 2 * 3.14 * (*r);
    return p;
}

int main() {
    int *r;
    float a = area(&r);  // Pass the address of the pointer
    float p = peri(r);
    printf("area: %f\nperimeter: %f", a, p);
    
    free(r);  // Free the allocated memory
    return 0;
}
