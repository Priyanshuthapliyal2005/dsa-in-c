#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
typedef struct Node Node;
void queueinsert(Node** head, int val) {
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

void queuepop(Node** head) {
    if (*head == NULL) {
        printf("Queue is empty, cannot pop.\n");
        return;
    }
    Node* curr=*head;
    *head=curr->next;
    free(curr);
}

void display(Node* head){
    printf("elements in queue are:\n");
    Node* curr=head;
    while(curr!=NULL){
        printf("%d\n",curr->val);
        curr=curr->next;
    }

}

int main(){
    Node* head=NULL;
    queueinsert(&head,1);
    queueinsert(&head,2);
    queueinsert(&head,3);
    queueinsert(&head,4);
    display(head);

    queuepop(&head);
    display(head);
}