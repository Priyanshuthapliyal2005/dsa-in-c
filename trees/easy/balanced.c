#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int max(int l,int r){
    if(l>r){
        return l;
    }
    else{
        return r;
    }
}
int height(node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

     return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);

}

bool isBalanced(node* root) {
    if (root == NULL) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) == 0 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }

    return false;
}

int main() {
    node* root = buildTree();
    if (isBalanced(root)) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct node {
//     int val;
//     struct node* left;
//     struct node* right;
// } node;

// node* createNode(int val) {
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->val = val;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// node* buildTree() {
//     int val;
//     printf("Enter The Value (or -1 to end): ");
//     scanf("%d", &val);

//     if (val == -1) {
//         return NULL;
//     }

//     node* root = createNode(val);

//     printf("For inserting in left of %d ", val);
//     root->left = buildTree();

//     printf("For inserting in right of %d ", val);
//     root->right = buildTree();

//     return root;
// }
// int max(int l,int r){
//     if(l>r){
//         return l;
//     }
//     else{
//         return r;
//     }
// }
// int height(node* root) {
//     if (root == NULL) {
//         return 0;
//     }

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     return 1 + max( leftHeight,rightHeight);
// }

// bool isBalanced(node* root) {
//     if (root == NULL) {
//         return true;
//     }

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);

//     if (abs(leftHeight - rightHeight) == 0 && isBalanced(root->left) && isBalanced(root->right)) {
//         return true;
//     }

//     return false;
// }

// int main() {
//     node* root = buildTree();
//     if (isBalanced(root)) {
//         printf("The tree is balanced.\n");
//     } else {
//         printf("The tree is not balanced.\n");
//     }

//     return 0;
// }
