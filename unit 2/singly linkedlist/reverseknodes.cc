#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};
typedef struct Node node;

void insert(node** head, int v) {
    node* temp = (node*)malloc(sizeof(node));
    temp->info = v;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}


void display(node* head) {
    node* temp = head;
    while (temp) {
        printf("%d", temp->info);
        if (temp->next) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}


node* reverse(node* head, int k) {
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (count == k) {
        current = head;
        count = 0;

        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != NULL) {
            head->next = reverse(next, k);
        }

        return prev;
    }
    return head;
}
int main() {
    node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    printf("simply linked list:");
    display(head);
    int k = 4; // Change this value to reverse in different group sizes
    head = reverse(head, k);
    printf("\nmodified linked list:");
    display(head);

    return 0;
}
