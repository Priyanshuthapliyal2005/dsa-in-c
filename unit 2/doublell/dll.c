#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node node;

void insertAtBeginning(node** head, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = (*head);
    newNode->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

void insertatend(node** head, int val) {
    node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;  // New node is always the last, so its next should be NULL
    if (*head == NULL) {
        *head = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;  // Set the previous node for the new last node
    }
}


void insertinbtw(node** head, int pos, int val) {
    node* curr = *head;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;

    if (pos == 1) {
        insertAtBeginning(head,val);
        return;
    } else {
        for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
            curr = curr->next;
        }
        if (curr != NULL) {
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next != NULL) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        } else {
            printf("Position out of bounds\n");
            free(newNode);
        }
    }
}
void deletelist(node** head, int key) {
    node* curr = *head;

    // Check if the list is empty
    if (curr == NULL) {
        printf("List is empty\n");
        return;
    }

    // Check if the key is in the first node
    if (curr->val == key) {
        *head = curr->next;
        free(curr);
        return;
    }

    // Iterate through the list to find the node with the key
    while (curr->next != NULL) {
        if (curr->next->val == key) {
            node* temp = curr->next;  // Store the node to be deleted
            curr->next = temp->next;  // Update the next pointer of the current node
            free(temp);               // Free the node containing the key
            return;
        }
        curr = curr->next;
    }

    // Key not found in the list
    printf("Key not found in the list\n");
}


void display(node* head) {
    node* curr = head;
    
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (curr != NULL) {
            printf("%d", curr->val);
            
            if (curr->next != NULL) {
                printf("->");
            }
            
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertatend(&head,6);
    insertinbtw(&head,3,3);
    deletelist(&head,1);
    display(head);

    // Don't forget to free the allocated memory
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
