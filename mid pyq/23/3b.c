#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node node;

void insertatsecondlaast(node** ptr, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*ptr == NULL) {
        *ptr = newnode;
    } else if ((*ptr)->next == NULL) {
        // List has only one node, insert newnode as the second node
        newnode->prev = *ptr;
        (*ptr)->next = newnode;
    } else {
        // Traverse to the second-to-last node
        node* current = *ptr;
        while (current->next->next != NULL) {
            current = current->next;
        }

        // Insert newnode as the second-to-last node
        newnode->next = current->next;
        newnode->prev = current;
        current->next->prev = newnode;
        current->next = newnode;
    }
}

void display(node* ptr) {
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* current = ptr;
    do {
        printf("%d ", current->val);
        current = current->next;
    } while (current != ptr);
    printf("\n");
}

int main() {
    node* ptr = NULL;

    // Example usage
    // insertatsecondlaast(&ptr, 10);
    // insertatsecondlaast(&ptr, 20);
    insertatsecondlaast(&ptr, 30);

    // Display the elements in the circular list
    display(ptr);

    // Don't forget to free the memory allocated for the nodes
    while (ptr != NULL) {
        node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    return 0;
}
