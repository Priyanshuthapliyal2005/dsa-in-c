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

void insertatend(node** head,node** last,int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = (*last)->next;
    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
    } else {
        (*last)->next = newNode;
    }
    *last=newNode;
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
    node* curr = head;
    if (curr == NULL) {
        return;
    } else {
        do {
            printf("%d ", curr->val);
            curr = curr->next;
        } while (curr != head);
    }
}

int main() {
    node* head = NULL;
    node* last = NULL;

    insertAtBeginning(&head, &last, 1);
    insertAtBeginning(&head, &last, 2);
    insertAtBeginning(&head, &last, 3);
    insertAtBeginning(&head, &last, 4);
    insertatend(&head,&last,0);
    insertinbtw(&head,&last,1,8);
    insertinbtw(&head,&last,7,8);
    insertinbtw(&head,&last,3,8);
    display(head, last);

    return 0;
}
