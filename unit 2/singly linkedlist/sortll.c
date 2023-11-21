#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtTail(struct Node** tail, struct Node* curr) {
    (*tail)->next = curr;
    (*tail) = curr;
}

struct Node* merge(struct Node* list1, struct Node* list2) {
    struct Node dummy;
    struct Node* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertAtTail(&tail, list1);
            list1 = list1->next;
        } else {
            insertAtTail(&tail, list2);
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = slow->next;
    slow->next = NULL;

    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    return merge(head, secondHalf);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node* head = newNode(15);
    head->next = newNode(90);
    head->next->next = newNode(37);
    head->next->next->next = newNode(24);
    head->next->next->next->next = newNode(9);

    printf("Original Linked List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted Linked List: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
