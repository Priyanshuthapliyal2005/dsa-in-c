#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void buildFromLevelOrder(struct node** root) {
    Node* head = NULL;
    printf("Enter the data for root: ");
    int data;
    scanf("%d", &data);
    *root = (struct node*)malloc(sizeof(struct node));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
    push(&head, *root);

    while (!empty(head)) {
        struct node* temp = pop(&head);

        printf("Enter left node for %d (-1 for no left child): ", temp->data);
        int leftData;
        scanf("%d", &leftData);
        if (leftData != -1) {
            temp->left = (struct node*)malloc(sizeof(struct node));
            temp->left->data = leftData;
            temp->left->left = NULL;
            temp->left->right = NULL;
            push(&head, temp->left);
        }

        printf("Enter right node for %d (-1 for no right child): ", temp->data);
        int rightData;
        scanf("%d", &rightData);
        if (rightData != -1) {
            temp->right = (struct node*)malloc(sizeof(struct node));
            temp->right->data = rightData;
            temp->right->left = NULL;
            temp->right->right = NULL;
            push(&head, temp->right);
        }
    }
}

void printTreeLevelOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    Node* queue = NULL;
    push(&queue, root);

    while (!empty(queue)) {
        struct node* temp = pop(&queue);
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            push(&queue, temp->left);
        }

        if (temp->right != NULL) {
            push(&queue, temp->right);
        }
    }
}

int main() {
    struct node* root = NULL;
    buildFromLevelOrder(&root);

    printf("Nodes in the tree in level order traversal:\n");
    printTreeLevelOrder(root);

    printf("\n\nTree Visualization:\n");
    printTreeVisual(root);

    return 0;
}
