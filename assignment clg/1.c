#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};
typedef struct Node node;

node *insertNode(int x, int y) {
    node *newNode = malloc(sizeof(node));
    newNode->coeff = x;
    newNode->exp = y;
    newNode->next = NULL;
    return newNode;
}

node *addPolynomials(node *p, node *q) {
    node *result = NULL;
    node *temp = NULL;

    while (p || q) {
        node *newNode = malloc(sizeof(node));
        newNode->next = NULL;

        if (p && q) {
            if (p->exp == q->exp) {
                newNode->exp = p->exp;
                newNode->coeff = p->coeff + q->coeff;
                p = p->next;
                q = q->next;
            } else if (p->exp > q->exp) {
                newNode->exp = p->exp;
                newNode->coeff = p->coeff;
                p = p->next;
            } else {
                newNode->exp = q->exp;
                newNode->coeff = q->coeff;
                q = q->next;
            }
        } else if (p) {
            newNode->exp = p->exp;
            newNode->coeff = p->coeff;
            p = p->next;
        } else {
            newNode->exp = q->exp;
            newNode->coeff = q->coeff;
            q = q->next;
        }

        if (!result) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return result;
}

void displayPolynomial(node *poly) {
    if (!poly) {
        printf("0\n");
        return;
    }

    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly) {
            if (poly->coeff >= 0) {
                printf("+");
            }
        }
    }
    printf("\n");
}

int main() {
    node *p = NULL;
    node *q = NULL;

    p = insertNode(5, 2);
    p->next = insertNode(4, 1);
    p->next->next = insertNode(2, 0);

    q = insertNode(-5, 1);
    q->next = insertNode(2, 0);

    printf("1st equation: ");
    displayPolynomial(p);
    printf("2nd equation: ");
    displayPolynomial(q);

    node *result = addPolynomials(p, q);
    printf("Addition: ");
    displayPolynomial(result);

    return 0;
}
