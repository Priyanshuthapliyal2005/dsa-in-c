#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// Function to insert a node at the end of a linked list
node* insertEnd(node* head, int val) {

    node* newNode = (node*)malloc(sizeof(node));
    
    newNode->data = val;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return head;
}

// Function to find the intersection of two sorted linked lists
node* findIntersection(node* head1, node* head2) {
    node* result = NULL;
    node** tail = &result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            *tail = (node*)malloc(sizeof(node));
            (*tail)->data = head1->data;
            (*tail)->next = NULL;
            tail = &((*tail)->next);
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
    }

    return result;
}

// Function to print the linked list
void displayList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    int n1, n2;

    // Input for the first linked list
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n1);
    printf("Enter sorted values for the first linked list:\n");
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        head1 = insertEnd(head1, val);
    }

    // Input for the second linked list
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter sorted values for the second linked list:\n");
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        head2 = insertEnd(head2, val);
    }

    // Find and print the intersection of the linked lists
    node* intersectionList = findIntersection(head1, head2);
    printf("Intersection of the linked lists: ");
    displayList(intersectionList);

    // Free memory
    freeList(head1);
    freeList(head2);
    freeList(intersectionList);

    return 0;
}
