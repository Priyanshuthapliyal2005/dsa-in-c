#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

node* createNode(int val){
    node* newNode=(node*)malloc(sizeof(node*));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

node* buildTree(node* root){
    int val;
    printf("Enter The Value :");
    scanf("%d",&val);
    root=createNode(val);
    if(val==-1){
        return;
    }
    printf("Enter value for inserting in left of %d:",val);
    root->left=buildTree(root->left);

    printf("Enter value for inserting in right of %d:",val);
    root->right=buildTree(root->right);

    return root;
}

void preorderTraversal(node* root){
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    node* root;
    buildTree(root);
    preorderTraversal(root);
}