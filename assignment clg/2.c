#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
typedef struct Node node;

// Function to create a new node
node *insertnode(int x, int y)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coeff = x;
    newnode->exp = y;
    newnode->next = NULL;
    return newnode;
}

// Function to add two polynomials
node *add(node *p, node *q)
{
    node *result = NULL;
    node *temp = NULL;

    while (p && q)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        if (p->exp == q->exp)
        {
            newnode->exp = p->exp;
            newnode->coeff = p->coeff + q->coeff;
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            newnode->exp = p->exp;
            newnode->coeff = p->coeff;
            p = p->next;
        }
        else
        {
            newnode->exp = q->exp;
            newnode->coeff = q->coeff;
            q = q->next;
        }

        if (result == NULL)
        {
            result = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    // If there are any remaining terms in p or q, add them to the result
    while (p)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = p->exp;
        newnode->coeff = p->coeff;
        temp->next = newnode;
        temp = temp->next;
        p = p->next;
    }

    while (q)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->exp = q->exp;
        newnode->coeff = q->coeff;
        temp->next = newnode;
        temp = temp->next;
        q = q->next;
    }

    return result;
}

// Function to display a polynomial
void show(node *poly)
{
    if (poly == NULL)
    {
        printf("0");
        return;
    }

    while (poly)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly)
        {
            if (poly->coeff >= 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}

int main()
{
    node *p = NULL;
    node *q = NULL;
    p = insertnode(5, 2);
    p->next = insertnode(4, 1);
    p->next->next = insertnode(2, 0);
    q = insertnode(-5, 1);
    q->next = insertnode(2, 0);

    printf("1st equation: ");
    show(p);
    printf("2nd equation: ");
    show(q);

    node *result = add(p, q);
    printf("Addition: ");
    show(result);

    return 0;
}
