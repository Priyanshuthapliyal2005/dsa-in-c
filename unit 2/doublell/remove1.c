#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

node* insertend(node** root, int val) {
    node* tail = *root;
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    if (*root == NULL) {
        *root = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
    }
}

node* insertbtw(node** root, int val, int pos) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    if (pos == 1) {
        newnode->next = *root;
        if (*root != NULL) {
            (*root)->prev = newnode;
        }
        *root = newnode;
    } else {
        node* curr = *root;
        int i = 1;
        while (i < pos - 1 && curr != NULL) {
            curr = curr->next;
            i++;
        }
        if (curr != NULL) {
            newnode->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = newnode;
            }
            curr->next = newnode;
            newnode->prev = curr;
        }
    }
}

node* removeunsort(node** root) {
    node* curr = *root;
    while (curr != NULL ) {
        node* fwd = curr->next;
        while (fwd != NULL ) {
            if (curr->val == fwd->val) {
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

void display(node* root) {
    node* curr = root;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node* root = NULL;
    insertbtw(&root, 4, 1);
    insertbtw(&root, 5, 2);
    insertbtw(&root, 8, 3);
    insertbtw(&root, 4, 4);
    insertbtw(&root, 8, 5);
    // insertend(&root, 1);
    // insertend(&root, 2);
    // insertend(&root, 3);
    // insertend(&root, 2);
    // insertend(&root, 3);
    // insertend(&root, 5);
    // insertend(&root, 5);
    printf("Original List: ");
    display(root);

    root = removeunsort(&root);

    printf("List after removing duplicates: ");
    display(root);

    return 0;
}
