#include <stdio.h>
#define MAX 15

void enqueue(int q[], int *f, int *r, int value) {
    if (*r == MAX - 1) {
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

int main() {
    int q[MAX];
    int front = -1;
    int rear = -1;

    // Example usage:
    enqueue(q, &front, &rear, 1);
    enqueue(q, &front, &rear, 2);
    enqueue(q, &front, &rear, 3);

    printf("Dequeued: %d\n", dequeue(q, &front, &rear));
    printf("Dequeued: %d\n", dequeue(q, &front, &rear));
    printf("Dequeued: %d\n", dequeue(q, &front, &rear));

    return 0;
}
