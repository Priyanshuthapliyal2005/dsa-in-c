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
        temp->next = NULL;
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
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    int x;

    if (head != NULL) {
        x = delete1();
        printf("\nDeleted element is: %d\n", x);
        display();

        x = delete1();
        printf("\nDeleted element is: %d\n", x);
        display();

        x = delete1();
        printf("\nDeleted element is: %d\n", x);
        display();

        x = delete1();
        printf("\nDeleted element is: %d\n", x);
        display();
    } else {
        printf("NOTHING TO DELETE\n");
    }

    return 0;
}
