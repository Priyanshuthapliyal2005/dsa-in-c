#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to parse a polynomial string and create a linked list
node *parsePolynomial(char *input)
{
    node *result = NULL;
    char *term = strtok(input, "+");

    while (term != NULL)
    {
        int coeff, exp;
        if (sscanf(term, "%dx^%d", &coeff, &exp) == 2)
        {
            node *newnode = insertnode(coeff, exp);

            if (result == NULL)
            {
                result = newnode;
            }
            else
            {
                newnode->next = result;
                result = newnode;
            }
        }
        term = strtok(NULL, "+");
    }

    return result;
}

int main()
{
    char equation1[100];
    char equation2[100];

    printf("Enter the first polynomial equation (e.g., 3x^2+2x^1-1x^0): ");
    scanf("%s", equation1);

    printf("Enter the second polynomial equation (e.g., 2x^2-5x^1+1x^0): ");
    scanf("%s", equation2);

    node *p = parsePolynomial(equation1);
    node *q = parsePolynomial(equation2);

    printf("First Polynomial: ");
    show(p);

    printf("Second Polynomial: ");
    show(q);

    node *result = add(p, q);

    printf("Addition Result: ");
    show(result);

    return 0;
}
