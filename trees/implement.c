#include<math.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct Node {
    struct node* data;
    struct Node* next;
};
typedef struct Node Node;
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void push(Node** head, struct node* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

struct node* pop(Node** head) {
    if (*head == NULL) {
        printf("Queue is empty, cannot pop.\n");
        return NULL;
    }
    Node* curr = *head;
    struct node* data = curr->data;
    *head = curr->next;
    free(curr);
    return data;
}

int empty(Node* head) {
    return head == NULL;
}

int heightOfTree(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

void printSpace(double n, struct node* removed) {
    for (; n > 0; n--) {
        printf("\t");
    }
    if (removed == NULL) {
        printf(" ");
    } else {
        printf("%d", removed->data);
    }
}

void printTreeVisual(struct node* root) {
    Node* treeLevel = NULL;
    Node* temp = NULL;
    push(&treeLevel, root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        struct node* removed = pop(&treeLevel);
        if (temp == NULL) {
            printSpace(numberOfElements / pow(2, counter + 1), removed);
        } else {
            printSpace(numberOfElements / pow(2, counter), removed);
        }
        if (removed == NULL) {
            push(&temp, NULL);
            push(&temp, NULL);
        } else {
            push(&temp, removed->left);
            push(&temp, removed->right);
        }
        if (empty(treeLevel)) {
            printf("\n\n");
            treeLevel = temp;
            temp = NULL;
            counter++;
        }
    }
}


int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);
    printf("Nodes in the tree is as follows: \n");
    printTreeVisual(root);
    return 0;
}