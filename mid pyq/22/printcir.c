#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node node;

void insertAtBeginning(node** head, node** last, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = (*head);

    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
    } else {
        (*last)->next = newNode;
    }

    *head = newNode;
}

void insertinbtw(node** head, node** last, int post, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL || post == 1) {
        insertAtBeginning(head, last, val);
        return;
    }

    node* temp = *head;

    for (int i = 1; i < post - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    // Update last if the new node is inserted after the last node.
    if (newNode->next == NULL) {
        *last = newNode;
    }
}

void display(node* head, node* last) {
    node* curr=head;
    if (curr == NULL) {
        return;
    } else {
        last=head;
    while(last->next->next!=NULL){
        last=last->next;
    }
        curr=last->next;
        do {
            printf("%d ", curr->val);
            curr = curr->next;
        } while (curr != last);
    }
}

void freeList(node** head) {
    if (*head == NULL) {
        return;
    }

    node* current = *head;
    node* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;  // Reset the head to NULL after freeing all nodes
}

int main() {
    node* head = NULL;
    node* last = NULL;
    insertinbtw(&head, &last, 1, 30);
    insertinbtw(&head, &last, 2, 35);
    insertinbtw(&head, &last, 3, 40);
    insertinbtw(&head, &last, 4, 45);
    insertinbtw(&head, &last, 5, 50);
    display(head, last);
    printf("\n");
    freeList(&head);
    return 0;
}
