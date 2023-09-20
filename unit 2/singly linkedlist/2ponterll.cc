#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node Node;

void insert(Node **f,Node **r,int v) {
    Node *temp=NULL;
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL){
        printf("overflow\n");
    }
    else{
        temp->info = v;
        temp->next = NULL;
        if(*f==NULL){
            *f=temp;
            *r=temp;
        }
        else{
            (*r)->next=temp;
            *r=temp;
        }
    }
}

int delete1(Node *f,Node *r) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    } else {
        int x = temp->info;
        if((*f)->next==NULL){
                *f=NULL;
                *r=NULL;
                return x;
        }
        else{
            node *temp=(*f)->node;
            (*f)->next=NULL;
            *f=temp;
            return x;
        }
    }
}

void display(Node *f,Node *r) {
    while(f!=r){
        printf("%d ",f->info);
        f=f->next;
    }
    printf("%d",f->info);
}

int main() {
    node *f=NULL;
    node *r=NULL;
    int ch, v, x;

    while (1) {
        printf("Enter the choice:\n");
        printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &v);
                insert(&f,&r,v);
                break;
            case 2:
                if (head != NULL) {
                    x = delete1(&f,&r);
                    printf("Deleted element is: %d\n", x);
                } else {
                    printf("List is empty, nothing to delete\n");
                }
                break;
            case 3:
                display(f,r);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
