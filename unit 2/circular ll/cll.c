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

void deletenode(node** head, node** last, int key) {
    if (*head == NULL) {
        return;
    } else {
        node* curr = *head;
        node* prev = NULL;
        
        while (curr->val != key) {
            if (curr->next == *head) {
                printf("Given node not found in the list\n");
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == *head) {
            prev = *head;
            while (prev->next != *head) {
                prev = prev->next;
            }
            *head = curr->next;
            prev->next = *head;

            // Update last if the last node is deleted
            if (curr == *last) {
                *last = prev;
            }
            
            free(curr);
        } else if (curr->next == *head && curr == *head) {
            prev->next = *head;
            free(curr);
        } else {
            prev->next = curr->next;

            // Update last if the last node is deleted
            if (curr == *last) {
                *last = prev;
            }

            free(curr);
        }
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
    printf("\n");
    deletenode(&head,&last,8);
    deletenode(&head,&last,8);
    deletenode(&head,&last,8);
    display(head,last);
    freeList(&head);
    return 0;
}
