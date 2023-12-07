#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node;

node* createNode(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* buildTree() {
    int val;
    printf("Enter The Value (or -1 to end): ");
    scanf("%d", &val);

    if (val == -1) {
        return NULL;
    }

    node* root = createNode(val);

    printf("For inserting in left of %d ", val);
    root->left = buildTree();

    printf("For inserting in right of %d ", val);
    root->right = buildTree();

    return root;
}

void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    node* root = buildTree();
    printf("Preorder Traversal: ");
    preorderTraversal(root);

    return 0;
}
