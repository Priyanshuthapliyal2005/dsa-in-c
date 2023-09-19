#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;

void insert(int v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = v;
    temp->next = head;
    head = temp;
}

int delete1() {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    } else {
        Node* temp = head;
        head = head->next;
        int x = temp->info;
        free(temp);
        return x;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, d, x;

    while (1) {
        printf("Enter the choice:\n");
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &d);
                insert(d);
                break;
            case 2:
                if (head != NULL) {
                    x = delete1();
                    printf("Deleted element is: %d\n", x);
                } else {
                    printf("List is empty, nothing to delete\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
