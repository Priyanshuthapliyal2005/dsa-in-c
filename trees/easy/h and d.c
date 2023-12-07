#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}node;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* buildTree(){
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
int height(node* root){
    if(!root){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int h=max(left,right)+1;
    return h;
}

int diameter(node* root){
    if(!root){
        return 0;
    }
    int d1=height(root->left);
    int d2=height(root->right);
    int d=max(d1+d2+1,max(d1,d2));
    return d;
}
int main(){
    node* root=buildTree();
    int ch;
    do{
        printf("Enter 1 to find height of tree\nEnter 2 to find diameter of tree");
        printf("\nEnter 0 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Height of tree is %d\n",height(root));
                break;
            case 2:
                printf("Diameter of tree is %d\n",diameter(root));
                break;
            case 0:
                break;
            default:
                printf("Enter valid choice\n");
        }
    }while(ch!=0);
    return 0;
}