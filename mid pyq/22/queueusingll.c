#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* next;
};
typedef struct node node;
void queueinsert(node** head, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
    } else {
        node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newnode;
    }
}

void queuepop(node** head) {
    if (*head == NULL) {
        printf("Queue is empty, cannot pop.\n");
        return;
    }
    node* curr=*head;
    *head=curr->next;
    free(curr);
}

void display(node* head){
    printf("elements in queue are:\n");
    node* curr=head;
    while(curr!=NULL){
        printf("%d\n",curr->val);
        curr=curr->next;
    }

}

int main(){
    node* head=NULL;
    queueinsert(&head,1);
    queueinsert(&head,2);
    queueinsert(&head,3);
    queueinsert(&head,4);
    display(head);

    queuepop(&head);
    display(head);
}