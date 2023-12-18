#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

void insertDescending(node** root, int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    node* current = *root;

    // Find the position to insert the new node in descending order
    while (current->next != NULL && current->next->val > val) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    newNode->prev = current;
    current->next = newNode;
}

// Function to print the doubly linked list
void printList(node* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

int main() {
    node* root = NULL;

    // Example usage
    insertDescending(&root, 5);
    insertDescending(&root, 3);
    insertDescending(&root, 8);
    insertDescending(&root, 1);

    // Print the doubly linked list
    printList(root);

    // Don't forget to free the allocated memory when done
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}
