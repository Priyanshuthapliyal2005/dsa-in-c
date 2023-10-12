#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
typedef struct Node node;

node* insertnode(node* head,int val){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->val=val;
    newNode->next=head;
    return newNode;
}

void printrev(node* head){
    if(head==NULL){
        return;
    }
    printrev(head->next);
    if(head->next)printf("->");
    printf("%d",head->val);
    
}
void freemem(node* head){
    node* curr=head;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        free(curr);
        curr=next;
    }
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        if(current->next)printf("->");
        current = current->next;
    }
}

int main(){
    node* head=NULL;
    head=insertnode(head,1);
    head=insertnode(head,2);
    head=insertnode(head,3);
    head=insertnode(head,4);
    head=insertnode(head,5);
    printf("Original Linked List: ");
    printList(head);
    printf("\nReversed Linked List: ");
    printrev(head);
    freemem(head);
}