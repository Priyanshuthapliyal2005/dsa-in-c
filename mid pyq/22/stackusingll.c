#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* next;
};
typedef struct node node;
void stackinsert(node** head,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->next=*head;
    if(*head){
        newnode->next=*head;
    }
    *head=newnode;
}
void stackpop(node** head){
    node* curr=*head;
    if(curr==NULL){
        return;
    }else{
        printf("value to be poppped id %d\n",curr->val);
        curr=curr->next;
    }
    *head=curr;
}
void display(node* head){
    printf("elements in stack are:\n");
    node* curr=head;
    while(curr!=NULL){
        printf("%d\n",curr->val);
        curr=curr->next;
    }

}

int main(){
    node* head=NULL;
    stackinsert(&head,1);
    stackinsert(&head,2);
    stackinsert(&head,3);
    stackinsert(&head,4);
    display(head);

    stackpop(&head);
    display(head);
}