#include<stdio.h>
#include<stdlib.h>

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

node* removeunsort(node** root) {
    node* curr = *root;
    while (curr != NULL && curr->next != NULL) {
        node* fwd = curr->next;
        while (fwd != NULL && fwd->next != NULL) {
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
    insertend(&root, 1);
    insertend(&root, 2);
    insertend(&root, 3);
    insertend(&root, 2);
    insertend(&root, 3);
    insertend(&root, 5);

    printf("Original List: ");
    display(root);

    root = removeunsort(&root);

    printf("List after removing duplicates: ");
    display(root);

    return 0;
}
