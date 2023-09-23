#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node Node;

void insert(Node** f, Node** r, int v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Overflow\n");
    } else {
        temp->info = v;
        temp->next = NULL;
        if (*f == NULL) {
            *f = temp;
            *r = temp;
        } else {
            (*r)->next = temp;
            *r = temp;
        }
    }
}

int delete1(Node** f, Node** r) {
    if (*f == NULL) {
        printf("List is empty\n");
        return -1;
    } else {
        Node* temp = *f;
        int x = temp->info;
        *f = (*f)->next;
        free(temp);
        if (*f == NULL) {
            *r = NULL; // Update rear when the last element is deleted
        }
        return x;
    }
}

void display(Node* f, Node* r) {
    while (f != NULL) {
        printf("%d ", f->info);
        f = f->next;
    }
    printf("\n");
}

int main() {
    Node* f = NULL; // Front
    Node* r = NULL; // Rear
    int ch, v, x;

    while (1) {
        printf("Enter the choice:\n");
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &v);
                insert(&f, &r, v);
                break;
            case 2:
                x = delete1(&f, &r);
                if (x != -1) {
                    printf("Deleted element is: %d\n", x);
                }
                break;
            case 3:
                display(f, r);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
