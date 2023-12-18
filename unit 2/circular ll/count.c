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

    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = *head;
        (*last)->next = newNode;
        *head = newNode;
    }
}

int countnodes(node* head){
    int count = 0;
    node* temp = head;

    if (head == NULL) {
        return count;
    }

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int main(){
    node* head = NULL;
    node* last = NULL;

    // Example usage
    insertAtBeginning(&head, &last, 5);
    insertAtBeginning(&head, &last, 3);
    insertAtBeginning(&head, &last, 8);
    insertAtBeginning(&head, &last, 8);

    // Print the count of nodes
    printf("Number of nodes: %d\n", countnodes(head));

    // Free the allocated memory (not shown in the provided code)
    
    return 0;
}
