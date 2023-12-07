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
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}
void PostorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    PostorderTraversal(root->right);
    PostorderTraversal(root->left);
    printf("%d ", root->val);
}
void print(node* root){
    if (root == NULL) {
        return;
    }
    int ch;
    do{
        printf("\n1.Preorder Traversal\n2.Postorder Traversal\n3.Inorder Traversal\n4.Exit\n");
        scanf("%d",&ch);
    switch(ch){

        case 1:
            preorderTraversal(root);
            break;
        case 2:
            PostorderTraversal(root);
            break;
        case 3:
            inorderTraversal(root);
            break;
        case 4:
            break;
        default:
            break;
    }
    }while(ch!=4);
}

int main() {
    node* root = buildTree();
    print(root);
    return 0;
}
