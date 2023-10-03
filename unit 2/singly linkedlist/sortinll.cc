#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node;
node* create(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insert(node** head,node* newnode){
    node* curr=*head;
    if(*head==NULL||(*head)->data>=newnode->data){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        
        while(curr->next!=NULL&&curr->next->data<newnode->data){
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
}
void display(node* head){
    node* temp=head;
    while(head!=NULL){
        printf("%d",temp->data);
        if(temp&&temp->next){
            printf("->");
        }
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    node* head=NULL;
    insert(&head,create(6));
    insert(&head,create(3));
    insert(&head,create(8));
    insert(&head,create(0));
    display(head);
    return 0;
}