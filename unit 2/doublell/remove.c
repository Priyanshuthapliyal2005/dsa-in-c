#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

node* insertBegin(node** root, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = *root;
    newnode->prev = NULL;
    if ((*root) != NULL) {
        (*root)->prev = newnode;
    }
    *root = newnode;
}

node* removeDuplicates(node** root) {
    node* curr = *root;
    while (curr != NULL) {
        node* fwd = curr->next;
        while (fwd != NULL) {
            if (fwd->val == curr->val) {
                node* temp = fwd;
                fwd->prev->next = fwd->next;
                if (fwd->next != NULL) {
                    fwd->next->prev = fwd->prev;
                }
                fwd = fwd->next;
                free(temp);
            } else {
                fwd = fwd->next;
            }
        }
        curr = curr->next;
    }
    return *root;
}

void print(node* root) {
    node* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

int main() {
    node* root = NULL;
    insertBegin(&root, 1);
    insertBegin(&root, 2);
    insertBegin(&root, 3);
    insertBegin(&root, 2);
    insertBegin(&root, 3);
    insertBegin(&root, 5);

    printf("Original List: ");
    print(root);
    printf("\n");

    root = removeDuplicates(&root);

    printf("List after removing duplicates: ");
    print(root);

    return 0;
}
