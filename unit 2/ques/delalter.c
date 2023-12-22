#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* insertend(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    node* temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

void deletealternate(node* head){
    node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        node* temp=curr->next;
        curr->next=temp->next;
        free(temp);
        curr=curr->next;
    }
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        if(temp->next!=NULL)
            printf("-> ");
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    node* head=NULL;
    int n;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        head=insertend(head,x);
    }
    printf("linked list is as follows:\n");
    display(head);
    deletealternate(head);
    printf("Alternate linked list is as follows:\n");
    display(head);
}