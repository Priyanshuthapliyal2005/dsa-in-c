//circular queue
#include<iostream>
using namespace std;
void enqueue(int q[], int size, int *f, int *r, int v) {
    if ((*r + 1) % size == *f) {
        cout << "Queue is full" << endl;
    } else {
        if (*f == -1) {
            *f = 0;
        }
        *r = (*r + 1) % size;
        q[*r] = v;
    }
}

int dequeue(int q[], int size, int *f, int *r) {
    if (*f == -1) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        int t = q[*f];
        if (*f == *r) {
            // Reset front and rear when there's only one element in the queue
            *f = -1;
            *r = -1;
        } else {
            *f = (*f + 1) % size;
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
int main()
{
    int size;
    cout<<"enter the size of queue: "<<endl;
    cin>>size;
    int q[size];
    int front = -1;
    int rear = -1;

    while (1) {
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n";
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                int v;
                cout<<"Enter the value to enqueue: ";
                cin>>v;
                enqueue(q,size,&front, &rear, v);
                break;
            case 2:
                dequeue(q, size,&front, &rear);
                break;
            case 3:
                display(q, front, rear); // Pass front and rear as parameters
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}