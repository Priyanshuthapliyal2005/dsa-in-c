#include <stdio.h>
#include <stdlib.h> // Include for dynamic memory allocation

void enqueue(int q[], int *f, int *r, int value, int size) {
    if (*r == size - 1) {
        printf("Queue is full\n");
    } else {
        (*r)++;
        q[*r] = value;
        if (*f == -1) {
            (*f)++;
        }
    }
}

int dequeue(int q[], int *f, int *r) {
    if (*f == -1) {
        printf("Queue is empty\n");
        return -1; // Return an error value
    } else {
        int t = q[*f];
        (*f)++;
        if (*f > *r) {
            *f = -1;
            *r = -1;
        }
        return t;
    }
}

void display(int q[], int f, int r) { // Pass front and rear as parameters
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in queue:\n");
        for (int i = f; i <= r; i++) {
            printf("%d\n", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the maximum number of elements you want to store in the queue: ");
    scanf("%d", &size);

    int *q = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory for the queue

    int front = -1;
    int rear = -1;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int value;
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, &front, &rear, value, size);
                break;
            case 2:
                dequeue(q, &front, &rear);
                break;
            case 3:
                display(q, front, rear); // Pass front and rear as parameters
                break;
            case 4:
                free(q); // Free the dynamically allocated memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
