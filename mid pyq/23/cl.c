#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

typedef struct Node node;

void insertatptr(node** head, node** ptr, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;

    if (*head == NULL && *ptr == NULL) {
        (*head) = newnode;
        (*ptr) = newnode;
        newnode->next = *head;
    } else {
        newnode->next = (*ptr)->next;
        (*ptr)->next = newnode;
    }

    *ptr = newnode;
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = head;
    do {
        printf("%d ", current->val);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    node* head = NULL;
    node* ptr = NULL;

    // Example usage
    insertatptr(&head, &ptr, 10);
    insertatptr(&head, &ptr, 20);
    insertatptr(&head, &ptr, 30);
    insertatptr(&head, &ptr, 40);

    // Display the elements in the circular list
    display(head);

    // Don't forget to free the memory allocated for the nodes
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
        if (current == head)
            break;  // Break the loop if we've completed one round in the circular list
    }

    return 0;
}
