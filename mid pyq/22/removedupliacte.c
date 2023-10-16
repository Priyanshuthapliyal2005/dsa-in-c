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
    newnode->next=NULL;
    if(*head){
        newnode->next=*head;
    }
    *head=newnode;
}
void stackpopduplicate(node** head) {
    node* curr = *head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}
void display(node* head){
    printf("Element's in stack are:\n");
    node* curr=head;
    while(curr!=NULL){
        printf("%d\n",curr->val);
        curr=curr->next;
    }

}

int main(){
    node* head=NULL;
    stackinsert(&head,1);
    stackinsert(&head,1);
    stackinsert(&head,2);
    stackinsert(&head,3);
    stackinsert(&head,3);
    stackinsert(&head,4);
    stackinsert(&head,4);
    display(head);

    stackpopduplicate(&head);
    display(head);
}