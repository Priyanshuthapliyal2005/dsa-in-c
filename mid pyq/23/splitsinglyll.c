#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

void insertEnd(node** head, int value) {
    node* newNode = (node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void splitLinkedList(node** head, int pos) {
    if (*head == NULL || pos <= 0) {
        printf("Invalid parameters.\n");
        return;
    }

    node *firstList = NULL, *secondList = NULL;
    node *firstTail = NULL, *secondTail = NULL;
    node* current = *head;
    int currentPosition = 1;

    while (current != NULL) {
        if (currentPosition <= pos) {
            if (firstList == NULL) {
                firstList = current;
                firstTail = current;
            } else {
                firstTail->next = current;
                firstTail = current;
            }
        } else {
            if (secondList == NULL) {
                secondList = current;
                secondTail = current;
            } else {
                secondTail->next = current;
                secondTail = current;
            }
        }

        current = current->next;
        currentPosition++;
    }

    // Adjust pointers and terminate the lists
    firstTail->next = NULL;
    secondTail->next = NULL;

    // Print the two resulting lists
    printf("First List: ");
    printList(firstList);

    printf("Second List: ");
    printList(secondList);
}

int main() {
    node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);

    printf("Original Linked List: ");
    printList(head);

    int pos = 2;

    splitLinkedList(&head, pos);

    return 0;
}
