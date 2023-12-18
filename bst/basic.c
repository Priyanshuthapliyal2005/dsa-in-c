#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} treenode;

treenode* create(int value) {
    treenode* newnode = (treenode*)malloc(sizeof(treenode));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

treenode* insert(treenode* root, int value) {
    if (root == NULL) {
        return create(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

treenode* searchnode(treenode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchnode(root->left, value);
    } else if (value > root->data) {
        return searchnode(root->right, value);
    }
}

treenode* findmin(treenode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return findmin(root->left);
    }
    return root;
}

treenode* findmax(treenode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right != NULL) {
        return findmax(root->right);
    }
    return root;
}

treenode* delete(treenode* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (x > root->data) {
        root->right = delete(root->right, x);
    } else if (x < root->data) {
        root->left = delete(root->left, x);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            treenode* temp;
            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        } else {
            treenode* temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inOrderTraversal(treenode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(treenode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(treenode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    treenode* root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int i;
    int x;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Enter the value to be searched: ");
    scanf("%d", &x);
    treenode* temp = searchnode(root, x);
    if (temp == NULL) {
        printf("Not found\n");
    } else {
        printf("Found\n");
    }

    printf("Minimum value: %d\n", findmin(root)->data);
    printf("Maximum value: %d\n", findmax(root)->data);

    printf("Enter the value to be deleted: ");
    scanf("%d", &x);
    root = delete(root, x);

    // Display the elements in sorted order after deletion
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory used by the tree
    free(root);

    return 0;
}
