#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
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

node* lca(node* root, node* n1, node* n2) {
    if (!root || root->val == n1->val || root->val == n2->val) {
        return root;
    }
    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);
    if (left && right) return root;
    else if (!left && !right) return NULL;
    else if (left && !right) return left;
    else return right;
}

int main() {
    node* root = buildTree();
    int n, p;
    printf("Enter the two nodes: ");
    scanf("%d %d", &n, &p);

    // Create nodes for n1 and n2
    node* n1 = createNode(n);
    node* n2 = createNode(p);

    node* ans = lca(root, n1, n2);

    if (ans)
        printf("The LCA is: %d", ans->val);
    else
        printf("Nodes not found in the tree.");

    return 0;
}
