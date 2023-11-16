
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node{
    int val;
    struct Node* next;
};
typedef struct Node Node;
void push(Node** head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
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

node* pop(Node** head) {
    if (*head == NULL) {
        printf("Queue is empty, cannot pop.\n");
        return;
    }
    Node* curr=*head;
    node* key=curr;
    *head=curr->next;
    free(curr);
    return key;
}

void empty(Node* head){
    Node* curr=head;
    if(!head){
        return;
    }
    pop(curr);
}

node* front(Node* head){
    Node* curr=head;
    if(!head){
        return;
    }
    node* key=pop(curr);
    return key;
}

void buildFromLevelOrder(node* &root){
    Node* head=NULL;
    printf("enter the data for root: ");
    scanf("%d",&data);
    root=(node*)malloc(sizeof(node));
    push(root,data);
    while(!empty(root)){
        node* temp=front(root);
        pop(root);
        printf("enter left node fro:",temp->data);
        int leftdata;
        scanf("%d",&leftdata);
        if(leftdata!=-1){
            temp->left=
        }

        printf("enter right node fro:",temp->data);
        int rightdata;
        scanf("%d",&rightdata);


    }

}

void printTreeInorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTreeInorder(root->left);
    printTreeInorder(root->right);
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    printf("Nodes in the tree in inorder traversal: \n");
    printTreeInorder(root);
    return 0;
}