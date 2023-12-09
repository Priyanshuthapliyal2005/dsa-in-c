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

node* solve(node* root, int value, int* k) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == value) {
        return root;
    }
    node* left = solve(root->left, value, k);
    node* right = solve(root->right, value, k);
    if (left == NULL && right != NULL) {
        (*k)--;
        if (*k == 0) {
            return root;
        }
        return right;
    }
    if (left != NULL && right == NULL) {
        (*k)--;
        if (*k == 0) {
            return root;
        }
        return left;
    }
    return NULL;
}

int kAncestor(node* root, int value, int k) {
    node* ans = solve(root, value, &k);
    if (ans == NULL || ans->val == value) {
        return -1;
    } else {
        return ans->val;
    }
}

int main() {
    node* root = buildTree();
    int val, k;
    printf("Enter the value and k: ");
    scanf("%d %d", &val, &k);
    int ans = kAncestor(root, val, k);
    printf("%d", ans);
    return 0;
}
