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

void rev(node** head){
    node* prev = NULL;
    node* current = *head;
    node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head=prev;

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
    rev(&head);
    printList(head);
    freemem(head);
}